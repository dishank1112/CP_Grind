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
#include<numeric>

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

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

template <typename T>
void read(vector<T> &arr) {
    for (auto &x : arr) {
        cin >> x;
    }
}

void dfs(int node, vector<int> &vis, vector<vector<int>> &adj) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, vis, adj);
        }
    }
}

// Cycle detection in Directed Graph
bool isCycleDirected(int node, vector<int> &vis, vector<int> &pathvis, vector<vector<int>> &adj) {
    vis[node] = 1;
    pathvis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            if (isCycleDirected(it, vis, pathvis, adj))
                return true;
        } else if (vis[it] && pathvis[it]) {
            return true;
        }
    }
    pathvis[node] = 0;
    return false;
}

// Cycle detection in Undirected Graph
bool isCycleIndirected(int node, int parent, vector<int> &vis, vector<vector<int>> &adj) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            if (isCycleIndirected(it, node, vis, adj))
                return true;
        } else if (it != parent) {
            return true;
        }
    }
    return false;
}

// Topological Sort
vector<int> topologicalSort(const vector<vector<int>> &adj) {
    int n = adj.size();
    vector<int> inDegree(n, 0);
    vector<int> topo;
    for (int i = 0; i < n; i++) {
        for (int neighbor : adj[i]) {
            inDegree[neighbor]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (int neighbor : adj[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    return topo;
}

struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
    bool isConnected(int u, int v) {
        return find(u) == find(v);
    }
};

bool compare(int u, int v, const vector<string> &g)
{
    return u < v ? g[u][v] == '1' : g[v][u] == '0';
}

void solve() {
    int n;
    cin >> n;
    vector<string> mat(n);
for (int i = 0; i < n; ++i)cin >> mat[i];
    
    vector<int> arr(n);
    for (int i = 0; i < n; ++i){
        arr[i] = i;
    }

    sort(arr.begin(), arr.end(), [&](int x, int y)
         {
             return compare(x,y, mat);
         });

        for (int i = 0; i < n; ++i){
            if (i + 1 == n){
                cout << arr[i] + 1 << "\n";
            }
            else{
                cout << arr[i] + 1 << " ";
            }
    }
}

int main() {
    fast_io();
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}