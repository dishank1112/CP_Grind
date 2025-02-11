#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;
const int inf = 1e18;
// wELL hELLo
void solve()
{
    int n;
    cin >> n;

    // Case 1: If `n` is odd and less than 27
    if (n % 2 == 1 && n < 27)
    {
        cout << "-1";
        return;
    }

    // Case 2: If `n` is even
    if (n % 2 == 0)
    {
        for (int i = 1; i <= n / 2; i++)
        {
            cout << i << " " << i << " ";
        }
        return;
    }

    // Case 3: If `n` is odd and greater than or equal to 27
    n -= 27; // Reduce `n` by 27
    cout << "1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9 10 10 11 11 12 12 15 15 ";
    for (int i = 0; i < n / 2; i++)
    {
        cout << (i + 16) << " " << (i + 16) << " ";
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }

    return 0;
}
