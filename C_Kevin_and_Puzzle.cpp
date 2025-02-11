#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <map>
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

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int MOD = 1e9 + 7;

ll f(const unordered_map<int, ll> &mp1, const unordered_map<int, ll> &mp2)
{
    ll total = 0;
    for (const auto &[_, cnt] : mp1)
    {
        total = (total + cnt) % MOD;
    }
    for (const auto &[_, cnt] : mp2)
    {
        total = (total + cnt) % MOD;
    }
    return total;
}

void solve()
{
    ll n;
    cin >> n;

    vector<int> arr(n);
    rep(i, 0, n){
        cin >> arr[i];
    }
// well hello there I am Jiraya U can send love

    unordered_map<int, ll> prev1, prev2;
    prev1[0] = 1;
    int element;
    rep(i, 1, n + 1)
    {
        element = arr[i - 1];
        ll findd = (prev1[element] + prev2[element]) % MOD;

        unordered_map<int, ll> curr1, curr2;

        if (findd > 0){
            curr1[element] = findd;
        }

        for (const auto &[l, cnt] : prev1){
            curr2[l + 1] = (curr2[l + 1] + cnt) % MOD;
        }

        prev1 = move(curr1);
        prev2 = move(curr2);
    }
    cout << f(prev1, prev2) << "\n";
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
