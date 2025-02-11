#include <iostream>
#include <map>
using namespace std;

#define ll long long

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve()
{
    ll n;
    cin >> n;
    map<ll, ll> arr; // Use map to handle ranges efficiently

    for (int i = 0; i < n; i++)
    {
        ll l, r;
        cin >> l >> r;
        arr[l]++;
        arr[r + 1]--;
    }

    ll current_overlap = 0;
    for (auto &[point, value] : arr)
    {
        current_overlap += value;
        if (current_overlap > 2)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main()
{
    fast_io();
    solve();
    return 0;
}