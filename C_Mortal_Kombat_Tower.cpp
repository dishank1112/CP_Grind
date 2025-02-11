#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <string>

using namespace std;

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
// well hello there I am jiraya u can send love letters later its really nice to meet ya!!!
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &it : a)cin >> it;
        
        int ans = 0;
        ans += a[0] == 1;
        for (int i = 1; i < n; ++i)
        {
            if (a[i] == 0)
            {
                continue;
            }
// well Hello there I am jiraay u can send 

            int j = i;
            while (j < n && a[j] == 1)
            {
                ++j;
            }
            ans += (j - i) / 3;
            i = j - 1;
        }
        cout << ans << endl;
    }

    return 0;
}