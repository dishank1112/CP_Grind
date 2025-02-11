#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bool isPerfect = true;
    for (int i = 0; i < n - 1; i++)
    {
        int interval = abs(arr[i] - arr[i + 1]);
        if (interval != 5 && interval != 7)
        {
            isPerfect = false;
            break;
        }
    }

    if (isPerfect)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    fast_io();

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
