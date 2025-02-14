#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define vi vector<int>

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void read(vector<int> &arr)
{
    for (auto &x : arr)
    {
        cin >> x;
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    read(arr);

    vector<ll> dp(n + 1, 1e9); 
    dp[n] = 0;                 

    for (int i = n - 1; i >= 0; i--)
    {
        int jump = i + arr[i] + 1; 
        if (jump <= n){
            dp[i] = min(1 + dp[i + 1], dp[jump]);
        }
        else{
            dp[i] = 1 + dp[i + 1];
        }
    }

    cout << dp[0] << endl;
}

int main()
{
    fast_io();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
