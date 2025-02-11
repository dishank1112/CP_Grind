#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <string>

using namespace std;

#define ll long long
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pii>
#define F first
#define S second
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1); // adjacency list
    vector<int> parent(n + 1, -1);  // parent array, initialize with -1
    vector<int> ds;                 // nodes with respect = 1

    // Read input and build adjacency list
    rep(i, 1, n + 1)
    {
        int p, respect;
        cin >> p >> respect;

        if (p != -1)
        {
            adj[p].push_back(i);
            parent[i] = p;
        }

        if (respect == 1)
        {
            ds.push_back(i);
        }
    }

    // Find nodes in `ds` that have all children with respect = 1
    vector<int> ans;
    for (int node : ds)
    {
        bool all_respected = true;
        for (int child : adj[node])
        {
            if (find(ds.begin(), ds.end(), child) == ds.end())
            {
                all_respected = false;
                break;
            }
        }

        if (all_respected)
        {
            ans.push_back(node);
        }
    }

    // Output result
    if (ans.empty())
    {
        cout << -1 << '\n';
    }
    else
    {
        sort(all(ans));
        for (int x : ans)
        {
            cout << x << " ";
        }
        cout << '\n';
    }
}

int main()
{
    fast_io();

        solve();
    

    return 0;
}
