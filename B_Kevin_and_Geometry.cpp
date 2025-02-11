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

struct DSU{
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

vector<pair<int,int>>dir  = {{-1,0},{1,0},{0,-1},{0,1}};
int f(int i, int j,vector<vector<int>>&arr){
    int n = arr.size();
    int m = arr[0].size();
    if(i>=0 && j>=0 && i<n && j<m )return 0;
      for(auto it : dir){
        int nr  = it.first+i;
        int nc  = it.second+j;
        for(auto it : dir){
            int nr  = it.first;
            int nc = it.second;
        }
      }
    return arr[i][j];

}

void f(vector<int>&arr,vector<int>&vec,vector<int>&rem){
    int dup = vec[0];
    int cnt = 2;
    for (int i=0;i<arr.size();i++){
        if (arr[i] == dup && cnt > 0){
            cnt--;
            continue;
        }
        rem.push_back(arr[i]);
    }

    for (int i = 0; i < rem.size() - 1; i++){
        if (rem[i + 1] < rem[i] + (2*dup)){
            cout <<dup<<" "<<dup<<" "<<rem[i]<<" "<<rem[i + 1]<<"\n";
            return ;
        }
    }
    cout << "-1"<<"\n";
       
}

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    read(arr);

    sort(arr.begin(), arr.end());
    vector<int> rem;
    map<int, int> mp;
    vector<int> vec;

    for (int i=0;i<n;i++){
        mp[arr[i]]++;
        if (mp[arr[i]] == 2)
        {
            vec.push_back(arr[i]);
        }
    }

    if (vec.empty()){
        cout << "-1"<<endl;
        return;
    }
    
    if (vec.size() >= 2){
        cout << vec[0] <<" "<< vec[0]<<" "<<vec[1]<<" "<<vec[1]<< "\n";
        return;
    }
    else{
        f(arr,vec,rem);
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--)solve();
    
}