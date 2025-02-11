#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        ll n, k;
        cin >> n >> k;

        unordered_map<ll, ll> brand_totals;
        for (ll i = 0; i < k; i++)
        {
            ll brand, cost;
            cin >> brand >> cost;
            brand_totals[brand] += cost;
        }

        // Collect all total costs into a vector for sorting
        vector<ll> top_vals;
        for (const auto &entry : brand_totals)
        {
            top_vals.push_back(entry.second);
        }

        // Sort in descending order to pick the top n
        sort(top_vals.rbegin(), top_vals.rend());

        ll max_revenue = 0;
        for (ll i = 0; i < min(n, (ll)top_vals.size()); i++)
        {
            max_revenue += top_vals[i];
        }

        cout << max_revenue << "\n";
    }

    return 0;
}
