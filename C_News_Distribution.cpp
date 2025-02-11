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


int dfs(int node,vector<int>&vis,vector<vector<int>>&adj,int cnt){
    if(vis[node])return 0;
    vis[node] = cnt;
    int ans  = node<adj.size() ? 1 : 0;
    for(auto it : adj[node]){
      ans += dfs(it,vis,adj,cnt);
    }
   return ans;
   
}


void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++){
        int x;
        cin >> x;
        vector<int> temp(x);
        for (int ind = 0; ind < x; ind++)cin >> temp[ind];
        
        for (int j = 1; j < temp.size(); j++)
        {
            int u = temp[j - 1];
            int v = temp[j];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    
    vector<int>ans(n+1,1);
    vector<int>vis(n+1,0);
    int cnt  = 0;
    for(int i=1;i<=n;i++){
      if(!vis[i]){
         cnt++;
         ans[cnt] = dfs(i,vis,adj,cnt);
      }
      cout<<ans[vis[i]]<<" ";
    }
   

}

int main() {
     solve();
    return 0;
}