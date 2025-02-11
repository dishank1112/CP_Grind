#include <iostream>
#include <algorithm>
using namespace std;

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve()
{
    int a, b;
    cin >> a >> b;

    int m = max(a, b);
    while (m % a != m % b)
    {
        m++;
    }

    cout << m << endl;
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
