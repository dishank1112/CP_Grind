#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <string>

using namespace std;
#define ll long long int
#define nline endl

void solve()
{
    ll n;
    cin >> n;

    ll rem[n];
    for (int i = 0; i < n - 1; i++)
        cin >> rem[i];

    ll ans[n] = {1000};

    for (int i = 0; i < n - 1; i++)
    {
        ans[i + 1] = ans[i] + rem[i];
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << nline;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}