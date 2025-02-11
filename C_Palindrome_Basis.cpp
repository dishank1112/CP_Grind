#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define ll long long
#define mod 1000000007

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<ll> f(ll limit)
{
    vector<ll> palindromes;

    for (ll num = 1; num <= limit; num++)
    {
        string s = to_string(num);
        string rev = s;
        reverse(rev.begin(), rev.end());
        if (s == rev)
        {
            palindromes.push_back(num);
        }
    }

    return palindromes;
}

ll tabulation(const vector<ll> &palindromes, ll target)
{
    ll m = palindromes.size();

    // DP table where `dp[i][j]` represents the number of ways to form `j` using the first `i` palindromes.
    vector<vector<ll>> dp(m + 1, vector<ll>(target + 1, 0));

    // Base Case: If the target is 0, there's exactly 1 way (use no palindromes).
    for (ll i = 0; i <= m; i++)
    {
        dp[i][0] = 1;
    }

    // Fill the DP table
    for (ll i = 1; i <= m; i++)
    {
        for (ll j = 1; j <= target; j++)
        {
            dp[i][j] = dp[i - 1][j]; // Don't pick the current palindrome
            if (j >= palindromes[i - 1])
            {
                dp[i][j] = (dp[i][j] + dp[i][j - palindromes[i - 1]]) % mod; // Pick the current palindrome
            }
        }
    }

    // Answer is the number of ways to form `target` using all `m` palindromes
    return dp[m][target];
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> palin = f(n);
    cout << tabulation(palin, n) << "\n";
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
