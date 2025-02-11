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

vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Directions: U, D, L, R

bool canEscape(int i, int j, vector<vector<int>> &vis, vector<vector<char>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    // Base case: if out of bounds, we can escape
    if (i < 0 || i >= n || j < 0 || j >= m)
        return true;

    // If the cell is already visited, return whether it can escape
    if (vis[i][j] != -1)
        return vis[i][j];

    // Mark the cell as visited (temporarily assume it cannot escape)
    vis[i][j] = 0;

    // Explore based on the character in the cell
    if (mat[i][j] == 'U')
    {
        if (canEscape(i - 1, j, vis, mat))
            vis[i][j] = 1;
    }
    else if (mat[i][j] == 'D')
    {
        if (canEscape(i + 1, j, vis, mat))
            vis[i][j] = 1;
    }
    else if (mat[i][j] == 'L')
    {
        if (canEscape(i, j - 1, vis, mat))
            vis[i][j] = 1;
    }
    else if (mat[i][j] == 'R')
    {
        if (canEscape(i, j + 1, vis, mat))
            vis[i][j] = 1;
    }
    else if (mat[i][j] == '?'){
        // Explore all four directions for '?'
        for (auto &[dx, dy] : dir)
        {
            if (canEscape(i + dx, j + dy, vis, mat))
            {
                vis[i][j] = 1;
                break;
            }
        }
    }

    // Return whether the cell can escape
    return vis[i][j];
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> vis(n, vector<int>(m, -1)); // -1: unvisited, 0: cannot escape, 1: can escape
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == -1)
            {
                canEscape(i, j, vis, mat);
            }
            if (vis[i][j] == 0)
                ans++; // Count cells that cannot escape
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
