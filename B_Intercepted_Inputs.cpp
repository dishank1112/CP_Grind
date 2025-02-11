#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define ll long long
#define vi vector<int>
#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

void solve()
{
    ll k;
    cin >> k;
    ll target = k - 2; 
    vector<ll> arr(k);

    for (ll i = 0; i < k; i++)
    {
        cin >> arr[i];
    }

    unordered_map<ll, ll> freq;
    for (int i = 0; i < k; i++)
    {
        freq[arr[i]]++;
    }

    for (ll i = 0; i < k; i++)
    {
        ll x = arr[i];
        if (target % x == 0)
        { 
            int complement = target / x;
            if (freq.count(complement))
            {
                if (complement == x && freq[complement] < 2)
                    continue;
                cout << x << " " << complement << "\n";
                return;
            }
        }
    }

    cout << "-1\n"; 
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
