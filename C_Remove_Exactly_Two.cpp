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

bool f2(vector<int> &adj, int v)
{
    int left = 0;
    int right = adj.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (adj[mid] == v)
        {
            return true;
        }
        if (adj[mid] < v)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return false;
}

void f(vector<int> &graph, vector<int> &ind_out_deg)
{
    sort(graph.begin(), graph.end(), [&](const int a, const int b) -> bool
         {
        if (ind_out_deg[a] != ind_out_deg[b]) {
            return ind_out_deg[a] > ind_out_deg[b];
        }
        return a < b; });
}

long long calci1(vector<int> &graph, vector<int> &ind_out_deg, vector<vector<int>> &adj)
{
    long long maxi = 0;
     
    for (int i = 0; i < graph.size(); ++i)
    {
        int node1 = graph[i];
        for (int j = i + 1; j < graph.size(); ++j)
        {
            int node2 = graph[j];
            if (!f2(adj[node1], node2))
            {
                long long p = (long long)(ind_out_deg[node1]) + ind_out_deg[node2] - 1;
                maxi = max(maxi, p);
                break;
            }
        }
    }
    return maxi;
}

long long calci2(int n, vector<vector<int>> &adj, vector<int> &ind_out_deg)
{
    long long maxi2 = 0;

    for (int node1 = 1; node1 <= n; ++node1)
    {
        for (auto &node2 : adj[node1])
        {
            if (node1 < node2)
            {
                long long temp = (long long)(ind_out_deg[node1]) + ind_out_deg[node2] - 2;
                maxi2 = max(maxi2, temp);
            }
        }
    }
    return maxi2;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1, vector<int>());
    vector<int> ind_out_deg(n + 1, 0);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ind_out_deg[u]++;
        ind_out_deg[v]++;
    }

    vector<int> graph(n);
    for (int i = 0; i < n; ++i){
        graph[i] = i + 1;
    }
    f(graph, ind_out_deg);

    for (int ind = 1; ind <= n; ++ind)
    {
        sort(adj[ind].begin(), adj[ind].end());
    }

    long long p = calci1(graph, ind_out_deg, adj);
    long long q = calci2(n, adj, ind_out_deg);

    int ans = max(p, q);

    cout << ans << "\n";
}

int main()
{
    fast_io();
    ll t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}