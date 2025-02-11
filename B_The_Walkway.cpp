#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define ll long long
#define rep(i, a, b) for (int i = a; i < b; i++)

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Function to compute floor division safely (since all numbers are nonnegative here)
ll countGap(ll gap, ll d)
{
    // gap is the number of benches between two "sellers" positions minus 1.
    return gap / d; // since gap = (a_i - a_{i-1} - 1)
}

void solve()
{
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> s(m);
    for (int i = 0; i < m; i++)
    {
        cin >> s[i];
    }
    // Insert sentinels:
    // We set a0 = 1 - d so that a1 - a0 - 1 = s[0] - (1-d) - 1 = s[0] + d - 2.
    // And a_{m+1} = n + 1.
    vector<int> pos;
    pos.push_back(1 - d);
    for (int x : s)
        pos.push_back(x);
    pos.push_back(n + 1);

    // Compute the base number of cookies eaten with no seller removed.
    // Note: Petya always eats a cookie at the very first bench (since he hasn't eaten any yet)
    // and at every seller position.
    ll base = 0;
    // For each gap between consecutive positions pos[i-1] and pos[i]:
    // He will eat floor((pos[i] - pos[i-1] - 1) / d) cookies from the "knapsack".
    for (int i = 1; i < pos.size(); i++)
    {
        base += countGap(pos[i] - pos[i - 1] - 1, d);
    }
    // Plus, note that at every seller bench (except possibly the first cookie eaten),
    // Petya eats a cookie. There are (m+1) positions in pos (excluding the first sentinel and last sentinel)
    // but the first cookie (at bench 1) is already accounted for by the simulation.
    // It turns out that the editorial formula adds an extra (m+1 - 2).
    base += (pos.size() - 2); // since pos.size() = m+2, add m (m+2 - 2)

    ll best = 1e18;
    int cnt = 0;
    // Now, try removing each seller (i from 1 to m, because pos[0] and pos[m+1] are sentinels)
    for (int i = 1; i <= m; i++)
    {
        // When we remove seller at pos[i], the two adjacent gaps merge:
        ll gap1 = pos[i] - pos[i - 1] - 1;
        ll gap2 = pos[i + 1] - pos[i] - 1;
        ll gapMerged = pos[i + 1] - pos[i - 1] - 1;

        ll reduction = countGap(gap1, d) + countGap(gap2, d) - countGap(gapMerged, d);
        ll candidate = base - reduction;

        if (candidate < best)
        {
            best = candidate;
            cnt = 1;
        }
        else if (candidate == best)
        {
            cnt++;
        }
    }

    cout << best-1 << " " << cnt << "\n";
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
