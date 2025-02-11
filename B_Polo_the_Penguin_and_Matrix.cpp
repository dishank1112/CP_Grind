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
// well Hello There I am Jiraya U can    
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
// Well 

void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>>arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
        cin>>arr[i][j];
       }
    } 

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        if(arr[i][j]%k != arr[0][0]%k){
            cout<<-1<<endl;
            return ;
        }
        }
    }
   vector<int>vec(n*m,0);
    int p = m;
   for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
        vec[i*p+j] = arr[i][j];
     }
   }
   sort(all(vec));
// well Hello there I am Jiraya U can send love letters later its really nice to meet ta

   int size  = vec.size();
   int med = vec[size/2];
    int ans = 0;
   for(int i=0;i<size;i++){
     ans += abs((med-vec[i]))/k;

   }
  cout<<ans<<endl;
}
void Dijkstra(int src, vector<vector<int>> &graph, vector<int> &store)
{
    int n = graph.size(); 
    store.assign(n, INT_MAX);
    store[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, src});

    while (!pq.empty())
    {
        // Extract the node with the smallest distance
        int u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();

        // If the distance is already greater, we skip it
        if (dist_u > store[u])
        {
            continue;
        }

        // Explore all the neighbors of u
        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] != INT_MAX)
            { // There is an edge from u to v
                int newDist = dist_u + graph[u][v];

                // If the distance through u is shorter, update the store vector
                if (newDist < store[v])
                {
                    store[v] = newDist;
                    pq.push({newDist, v}); // Push the new distance and node into the priority queue
                }
            }
        }
    }
}

int main() {
    fast_io();
    solve();
    
    return 0;
}