#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define ll long long

bool is_composite(int num)
{
    if (num <= 1)
        return false;
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return true;
        }
    }
    return false;
}

void solve()
{
    ll n;
    cin >> n;
    vector<int> evens;
    vector<int> odds;

    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
            evens.push_back(i);
        else
            odds.push_back(i);
    }

    vector<int> ans;

    for (int p : odds)
    {
        ans.push_back(p);
    }

    bool found = false;
    int num_founded = -1;
    for (int even : evens){
        if (is_composite(odds.back() + even)){
             num_founded = even;
            ans.push_back(even);
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << -1 << endl;
        return;
    }
    for (int q : evens)
    {if(q == num_founded)continue;
        else ans.push_back(q);
    }

    for (int num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
