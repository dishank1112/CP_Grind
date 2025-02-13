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

bool check(ll val)
{
    string p = to_string(val);
    for (auto s : p)
    {
        if (s == '7')
            return true;
    }

    return false;
}
void solve()
{
    ll n;
    cin >> n;

    if (check(n))
    {
        cout << 0 << endl;
        return;
    }

    string s = "9";
    ll mn = 1e18;
    while (s.size() <= 10)
    {
        ll val = stoll(s);
        ll ch = n;
        for (ll i = 0; i < 100; i++)
        {
            ch += val;
            if (check(ch))
            {
                mn = min(mn, (i + 1));
                break;
            }
        }
        s += "9";
    }

    cout << mn << endl;
}

int main() {
    fast_io();
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}