#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <climits>
using namespace std;
typedef long long ll;

template <typename T>
void read(vector<T> &arr)
{
    for (auto &x : arr)
    {
        cin >> x;
    }
}

void dfs(int node, vector<int> &vis, vector<vector<int>> &adj)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, adj);
        }
    }
}

// Cycle detection in Directed Graph
bool isCycleDirected(int node, vector<int> &vis, vector<int> &pathvis, vector<vector<int>> &adj)
{
    vis[node] = 1;
    pathvis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (isCycleDirected(it, vis, pathvis, adj))
                return true;
        }
        else if (vis[it] && pathvis[it])
        {
            return true;
        }
    }
    pathvis[node] = 0;
    return false;
}

// Cycle detection in Undirected Graph
bool isCycleIndirected(int node, int parent, vector<int> &vis, vector<vector<int>> &adj)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (isCycleIndirected(it, node, vis, adj))
                return true;
        }
        else if (it != parent)
        {
            return true;
        }
    }
    return false;
}

// Topological Sort
vector<int> topologicalSort(const vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> inDegree(n, 0);
    vector<int> topo;
    for (int i = 0; i < n; i++)
    {
        for (int neighbor : adj[i])
        {
            inDegree[neighbor]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (int neighbor : adj[node])
        {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }
    return topo;
}

struct DSU
{
    vector<int> parent, rank;
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int find(int u)
    {
        if (parent[u] != u)
        {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    void unite(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV)
        {
            if (rank[rootU] > rank[rootV])
            {
                parent[rootV] = rootU;
            }
            else if (rank[rootU] < rank[rootV])
            {
                parent[rootU] = rootV;
            }
            else
            {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
    bool isConnected(int u, int v)
    {
        return find(u) == find(v);
    }
};

struct stt
{
    ll x, y;
};

vector<ll> f1(vector<ll> &arr){

    if (arr.empty())return {0, 0, 0, 0};

    ll mini = arr[0];
    ll mini_tot = arr[0];
    ll maxi = arr[0];
    ll maxi_tot= arr[0];

    ll sum = 0;
    ll min_suffix = LLONG_MAX;
    ll max_suffix = LLONG_MIN;

    for (auto p : arr){
        mini = min(p, mini + p);
        mini_tot = min(mini_tot, mini);
        maxi = max(p, maxi + p);
        maxi_tot = max(maxi_tot, maxi);
        sum += p;
        min_suffix = min(min_suffix, sum);
        max_suffix = max(max_suffix, sum);
    }

    min_suffix = min(min_suffix, 0LL);
    max_suffix = max(max_suffix, 0LL);
    vector<ll>arr1;
    arr1.push_back(mini_tot);
    arr1.push_back(maxi_tot);
    arr1.push_back(min_suffix);
    arr1.push_back(max_suffix);
    return arr1;
}

vector<stt> f2(vector<stt> &arr){
    sort(arr.begin(), arr.end(), [&](const stt &p, const stt &q) -> bool{
        if (p.x != q.x) return p.x < q.x;
        return p.y < q.y; });
    vector<stt> merged;
    for (auto &r : arr){
        if (merged.empty() || r.x > merged.back().y + 1)
        {
            merged.push_back(r);
        }
        else merged.back().y = max(merged.back().y, r.y);
        
    }
    return merged;
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    
    bool one = false;
    bool neg_one = false;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int special = -1;
    for(int i=0;i<n;i++){
        if (a[i] == 1)one = true;
        if (a[i] == -1)neg_one = true;
        if (a[i] != 1 && a[i] != -1)special = i;
    }

    vector<stt> inters;
    if (special == -1){
         vector<ll>arr=f1(a);
         ll mini = arr[0];
         ll maxi = arr[1];

        if (one && neg_one){
            inters.push_back(stt{mini, maxi});
        }

        else if (one){
            inters.push_back(stt{1, (ll)n});
        }

        else{
            inters.push_back(stt{-n, -1});
        }
        inters.push_back(stt{0, 0});
    }
    else{
        vector<ll> east(a.begin(), a.begin() + special);
        vector<ll> west(a.begin() + special + 1, a.end());

        ll element = a[special];

        vector<ll>vec=f1(east);
        ll mini_left = vec[0];
        ll maxi_left = vec[1];
        ll mini_suff_l=vec[2];
        ll maxi_suff_l=vec[3];

        vector<ll> vec2 = f1(west);

        ll mini_right=vec2[0];
        ll maxi_right=vec2[1];
        ll mini_pre_l=vec2[2];
        ll maxi_pre_r=vec2[3];

        ll element_mini = mini_suff_l + element + mini_pre_l;
        ll element_maxi = maxi_suff_l + element + maxi_pre_r;
        
        inters.push_back(stt{mini_left, maxi_left});
        inters.push_back(stt{mini_right, maxi_right});
        inters.push_back(stt{element_mini, element_maxi});
        inters.push_back(stt{0, 0});
    }

    vector<stt>ds = f2(inters);

    set<ll> st;
    for (auto &p : ds){
        for (ll val = p.x; val <= p.y; val++)st.insert(val);
    }

    cout << st.size()<<"\n";
    for (auto p : st)cout<<p<<" ";

    cout << "\n";
}

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
