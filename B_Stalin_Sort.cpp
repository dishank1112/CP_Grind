#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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
    vector<ll> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int res = 1e9+7;

    for (int ind = 0; ind < n; ind++){
        int cnt = 0;
        for (int j = ind + 1; j < n; j++){
            if (arr[j] > arr[ind]) cnt++;
        }

        res = min(res, cnt + ind);
    }
    cout << res << endl;
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
