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
#define int long long
void solve()
{
    int l, r;
    cin >> l >> r;
    
    int bit = 30;

    int total = 0;
    while (bit >= 0)
    {    int element  = 1ll<<bit;
        if ((l & element) == (r & element))
        {
            if (l & element)
                total += element;
        }
        else
            break;
        --bit;
    }
    int lint = 1ll<<bit;
    if (r > total + lint)cout << total + lint - 1 << ' ' << total + lint << ' ' << total + lint + 1 << '\n';
    else  cout << total + lint - 2 << ' ' << total +lint - 1 << ' ' << total + lint << '\n';
    
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
