#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

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

int f(int ind, vector<int> &arr, int needed, vector<vector<int>> &dp)
{
    if (ind >= arr.size() && needed == 0)
    {
        return 0;
    }
    else if (ind >= arr.size())
    {
        return -1000000000;
    }

    if (dp[ind][needed] != -1)
        return dp[ind][needed];

    // If arr[ind] is odd, including it toggles 'needed'
    int new_needed = (arr[ind] % 2 != 0) ? (1 - needed) : needed;

    dp[ind][needed] = max(arr[ind] + f(ind + 1, arr, new_needed, dp),
                          f(ind + 1, arr, needed, dp));

    return dp[ind][needed];
}

void solve()
{
    int n;
    cin >> n; // Read number of elements.

    vector<int> arr(n);
    read(arr);

    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    int ans = f(0, arr, 1, dp);

    if (ans <= -1000000000)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
}

int main()
{
    fast_io();
    solve();
    return 0;
}
