#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define vi vector<int>

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

int f(vector<ll> &arr, vector<ll> &brr, ll n)
{
    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());

    ll j = 0;
    ll i = 0;

    ll ans = 0;
    while (i < n)
    {

        if (arr[j] < brr[i])
        {
            i++;
            j++;
        }
        else
        {
            while (i < n && arr[j] >= brr[i])
            {
                ans++;
                i++;
            }
            j++;
            i++;
        }
    }
// well hello There I am
    return ans;
}

    void solve()
    {
        ll n, m;
        cin >> n >> m;

        vector<ll> arr(n);
        arr[0] = 1;
        for (ll i = 1; i < n; i++)
            cin >> arr[i];

        vector<ll> brr(n);
        for (ll i = 0; i < n; i++)
            cin >> brr[i];
        ll curr = f(arr, brr, n);

        ll low = 1;
        ll high = m;
        ll ans = 1;

        while (low <= high)
        {
            ll mid = low + (high - low) / 2;
            arr[0] = mid;
            if (f(arr, brr, n) == curr)
            {
                low = mid + 1;
                ans = mid;
            }
            else
                high = mid - 1;
        }

        ans = curr * m + (m - ans);
        cout << ans << '\n';
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
