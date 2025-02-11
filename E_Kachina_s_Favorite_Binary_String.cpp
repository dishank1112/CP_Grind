#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <string>

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

template <typename T>
void read(vector<T> &arr)
{
    for (auto &x : arr)
    {
        cin >> x;
    }
}

int query(int l, int r)
{
    cout << "? " << l << " " << r << endl;
    cout.flush();
    int y;
    cin >> y;
    return y;
}

void solve()
{
    ll n;
    cin >> n;

    string ans;
    int prev = 0;
    int cnt0 = 0;

    rep(i, 1, n)
    {
        int x = query(1, i + 1);

        if (prev == 0)
        {
            if (x == 0)
            {
                continue; 
            }
            else
            {
                if (x > i)
                {
                    cout << "! IMPOSSIBLE" << endl;
                    return;
                }
                else
                {
                    rep(j, 0, i - x)
                    {
                        ans.pb('1');
                    }
                    rep(j, 0, x)
                    {
                        ans.pb('0');
                    }
                }
            }
            ans.pb('1'); 
            cnt0 = x;
            prev = x;
        }
        else
        {
            if (x > prev)
            {
                if (x - prev == cnt0)
                {
                    ans.pb('1');
                    prev = x;
                }
                else
                {
                    cout << "! IMPOSSIBLE" << endl;
                    return;
                }
            }
            else if (x == prev)
            {
                ans.pb('0');
                cnt0++;
            }
            else
            {
                cout << "! IMPOSSIBLE" << endl;
                return;
            }
        }
    }

    if (ans.size() < n)
    {
        cout << "! IMPOSSIBLE" << endl;
        return;
    }

    cout << "! " << ans << endl;
    cout.flush();
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
