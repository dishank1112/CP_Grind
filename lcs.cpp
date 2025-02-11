#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define pb push_back

string f(vector<vector<int>> &dp, string str1, string str2)
{
    int n = dp.size() - 1;
    int m = dp[0].size() - 1;
    string ans = "";

    while (n > 0 && m > 0)
    { // Ensure bounds
        if (str1[n - 1] == str2[m - 1])
        { // Check characters at (n-1) and (m-1)
            ans += str1[n - 1];
            n--;
            m--;
        }
        else if (dp[n - 1][m] > dp[n][m - 1])
        {
            n--;
        }
        else
        {
            m--;
        }
    }

    reverse(ans.begin(), ans.end()); // Reverse the string
    return ans;
}

int main()
{
    string str1 = "dishank";
    string str2 = "ishan";
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Fill DP table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << "Length of LCS: " << dp[n][m] << endl;
    cout << "LCS: " << f(dp, str1, str2) << endl;

    return 0;
}
