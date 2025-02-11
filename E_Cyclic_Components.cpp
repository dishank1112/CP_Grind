#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool isValidCycle(int node, vector<vector<int>> &adj, vector<int> &vis)
{
    queue<pair<int, int>> q; // {current node, parent node}
    q.push({node, -1});
    bool isCycle = true; // To track if it's a valid cycle
    vis[node] = 1;

    while (!q.empty())
    {
        int curr = q.front().first;
        int parent = q.front().second;
        q.pop();

        if (adj[curr].size() != 2)
        {
            isCycle = false; // Not a valid cycle if any node doesn't have exactly 2 neighbors
        }

        for (auto neighbor : adj[curr]){
    
            if (!vis[neighbor])
            {
                vis[neighbor] = 1; 
                q.push({neighbor, curr});
            }
            else if (neighbor != parent)
            {
                isCycle &= true;
            }
        }
    }
 
    return isCycle;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
// well hello there i am jiraya u can send love letters later its really nice to meet ya!!

    int ans = 0;
    vector<int> vis(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && adj[i].size() > 0)
        {
            if (isValidCycle(i, adj, vis))
            {
                ans++;
            }
        }
    }

    cout << ans << "\n";
}

int main()
{
    fast_io();
    solve();
    return 0;
}
