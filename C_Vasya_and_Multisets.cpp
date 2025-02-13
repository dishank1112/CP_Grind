#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define ll long long

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, vector<int>> mp;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }

    int cnt1 = 0, cnt2 = 0;
    for (auto &it : mp)
    {
        if (it.second.size() == 1)
        {
            cnt1++;
        }
        else if (it.second.size() > 2)
        {
            cnt2++;
        }
    }

    vector<char> ans(n, 'B');

    if (cnt1 % 2 == 0)
    {
        cout << "YES\n";
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (mp[a[i]].size() == 1)
            {
                if (flag)
                    ans[i] = 'A';
                flag = !flag;
            }
        }
    }
    else if (cnt1 % 2 != 0 && cnt2 > 0)
    {
        cout << "YES\n";
        bool flag = true;
        bool changed = false;
        for (int i = 0; i < n; i++)
        {
            if (mp[a[i]].size() == 1)
            {
                if (flag)
                    ans[i] = 'A';
                flag = !flag;
            }
        }
        for (auto &it : mp)
        {
            if (it.second.size() > 2 && !changed)
            {
                ans[it.second[0]] = 'A';
                changed = true;
            }
        }
    }
    else
    {
        cout << "NO\n";
        return;
    }

    for (char c : ans)
        cout << c;
    cout << "\n";
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
