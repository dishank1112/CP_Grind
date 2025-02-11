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

void dfs(int node, vector<int> &vis, vector<vector<int>> &adj,stack<int>&st) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, vis, adj,st);
        }
    }
    st.push(node);
}




void topo(vector<vector<int>>&adj){
    int n = adj.size();
    vector<int>vis(n,0);
    stack<int>st;
    for(int i=0;i<n;i++){
       if(!vis[i]){
        dfs(i,vis,adj,st);
       }
    }
    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
}



void solve() {
    vector<vector<int>>adj={{1},{},{3},{1}};
    topo(adj);    
}

int main() {
    solve();
    
    return 0;
}