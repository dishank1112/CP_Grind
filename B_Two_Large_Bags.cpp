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
#define nl "\n" 

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

void solve()
{
    ll n;
    cin >> n;

    vector<ll> a(n + 1, 0);
    for (int i = 0; i < n; i++){ 
        ll val;
        cin >> val;
        a[val]++;
    }

    for (int i = 1; i < n; i++){
        if (a[i] == 1)
        {
            cout << "No" << nl;
            return;
        }
        else if (a[i] != 0){
            ll occurance = a[i];
            a[i] = 2;
            a[i + 1] += occurance - 2;
        }
    }

    for (int i=0;i<n;i++){
        if (a[i] % 2 == 1)
        {
            cout << "No" << nl;
            return;
        }
    }

    cout << "Yes" << nl;
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
