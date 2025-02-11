#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

pii bfs(int start, int n, vector<pii> &edges)
{
    vi dis(n + 1, -1);

    queue<int> qq;
    qq.push(start);
    dis[start] = 0;
    int farr = start;

    while (!qq.empty())
    {
        int u = qq.front();
        qq.pop();
        for (auto &[x, y] : edges)
        {
            if (x == u && dis[y] == -1)
            {
                dis[y] = dis[u] + 1;
                qq.push(y);
                if (dis[y] > dis[farr])
                    farr = y;
            }
            else if (y == u && dis[x] == -1)
            {
                dis[x] = dis[u] + 1;
                qq.push(x);
                if (dis[x] > dis[farr])
                    farr = x;
            }
        }
    }

    return {farr, dis[farr]};
}

bool f2(ll n, ll d, ll l){

    vector<pii> edges;

    rep(i, 1, d + 1) edges.pb({i, i + 1});

    int nextt = d + 1;
    queue<int> q;

    rep(i, 2, d + 1) q.push(i);

    int leaves_req = l - 2;

    rep(i, 0, leaves_req)
    {
        if (nextt >= n || q.empty())break;

        int parent = q.front();

        edges.pb({parent, nextt + 1});

        q.push(nextt + 1);

        nextt++;
    }

    while (nextt < n){
        if (q.empty())break;

        int parent = q.front();
        q.pop();
        edges.pb({parent, nextt + 1});
        q.push(nextt + 1);
        nextt++;
    }

    if (nextt != n)
    {
        cout << "-1\n";
        return false;
    }

    vi degree(n + 2, 0);

    for (auto &[u, v] : edges)
    {
        degree[u]++;
        degree[v]++;
    }

    int cnt_leaf = 0;
    rep(i, 1, n + 1)
    {
        if (degree[i] == 1)
            cnt_leaf++;
    }

    if (cnt_leaf != l)
    {
        cout << "-1\n";
        return false;
    }

    pii first = bfs(1, n, edges);

    pii second = bfs(first.first, n, edges);


    if (second.second != d){
        cout << "-1\n";
        return false;
    }

    for (auto &[u, v] : edges){
        cout << u << " " << v << "\n";
    }

    return true;
}

void f1()
{
    ll n, d, l;
    cin >> n >> d >> l;

    if (d == 1)
    {
        if (n == 2 && l == 2)
        {
            cout << "1 2\n";
        }
        else
        {
            cout << "-1\n";
        }
    }
    else if (d == 2)
    {
        if (l == n - 1 && n >= 3)
        {
            rep(i, 2, n + 1)
                    cout
                << "1 " << i << "\n";
        }
        else
        {
            cout << "-1\n";
        }
    }
    else
    {
        if (l >= 2 && l <= n - d + 1 && n >= d + 1)
        {
            if (l > 2 + (d - 1) * max(0LL, n - d - 1))
            {
                cout << "-1\n";
                return;
            }

            f2(n, d, l);
        }
        else
        {
            cout << "-1\n";
        }
    }
}

int main()
{
    fast_io();

    ll t;
    cin >> t;
    while (t--)
    {
        f1();
    }
    return 0;
}