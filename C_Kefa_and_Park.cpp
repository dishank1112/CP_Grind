#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include<queue>
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
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n + 1, 0);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    vector<vector<int>> adj(n + 1);

    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, int> leaf;
    for (int i = 1; i <= n; i++){ 
        if (adj[i].size() == 1)
            leaf[i]++;
    }

    vector<int> vis(n + 1, 0); 
    queue<pair<int, int>> q;

    vis[1] = 1;
    q.push({1, arr[1]});

    int ans = 0;

    while (!q.empty()){
        int node = q.front().first;
        int cat = q.front().second;
        q.pop();

        bool isLeaf = (node != 1 && leaf.find(node) != leaf.end());
        if (isLeaf && cat <= k){
            ans++;
        }

        for (auto it : adj[node]) {
            if (!vis[it])
            {
                vis[it] = 1; 
                int newCat = (arr[it] == 1) ? cat + 1 : 0;
                if (newCat <= k)
                {
                    q.push({it, newCat});
                }
            }
        }
    }

    cout << ans << "\n";
    return ;
}

int main() {
    fast_io();
        solve();
    

    return 0;
}