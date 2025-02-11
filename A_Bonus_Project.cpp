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

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> bonus(n), price_unit(n);
    read(bonus);
    read(price_unit);

    vector<int> max_work(n);

    for (int i = 0; i < n; i++)
    {
        max_work[i] = bonus[i] / price_unit[i];
    }

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        if (k == 0)
        {
            ans[i] = 0;
        }
        else if (max_work[i] < k)
        {
            ans[i] = max_work[i];
            k -= max_work[i];
        }
        else
        {
            ans[i] = k;
            k = 0;
        }
    }

    if (k > 0)
    {
        fill(all(ans), 0);
    }

    for (int x : ans)
        cout << x << " ";
    cout << endl;
}

int main()
{
    fast_io();
    solve();
    return 0;
}