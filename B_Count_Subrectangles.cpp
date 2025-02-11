#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define ll long long
#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);
void solve(){    
    int n, m;
    ll k;
    cin >> n >> m >> k;
// well hello thre I am jiraya u can send love letters 

    vector<int> arr1(n), arr2(m);
    for (int &x : arr1)
        cin >> x;
    for (int &x : arr2)
        cin >> x;

    vector<ll> contrib1(n + 1, 0), contrib2(m + 1, 0);

    // Compute contributions for arr1
    for (int i = 0, count = 0; i < n; ++i)
    {
        if (arr1[i] == 1)
        {
            count++;
        }
// well hello there I am jiraya u can send love letters later its really nice to meet ya!!
// well Hello there I am Jiraya u can send love letters later its really nice to meet ya
        else
        {
            for (int len = 1; len <= count; len++)
            {
                contrib1[len] += count - len + 1;
            }
            count = 0;
        }
        if (i == n - 1 && count > 0)
        { // Handle the last segment
            for (int len = 1; len <= count; len++)
            {
                contrib1[len] += count - len + 1;
            }
        }
    }

    // Compute contributions for arr2
    for (int i = 0, count = 0; i < m; ++i)
    {
        if (arr2[i] == 1)
        {
            count++;
        }
        else
        {
            for (int len = 1; len <= count; len++)
            {
                contrib2[len] += count - len + 1;
            }
            count = 0;
        }
        if (i == m - 1 && count > 0)
        { // Handle the last segment
            for (int len = 1; len <= count; len++)
            {
                contrib2[len] += count - len + 1;
            }
        }
    }

    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (k % i == 0)
        {
            ll j = k / i;
            if (j <= m)
            {
                ans += contrib1[i] * contrib2[j];
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
