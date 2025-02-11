#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int W = 50;                          // Maximum weight of the knapsack
    vector<int> weights = {10, 20, 30};  // Weights of the items
    vector<int> values = {60, 100, 120}; // Values of the items
    int n = weights.size();              // Number of items

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= n; i++)
    { // Iterate over items
        for (int w = 0; w <= W; w++)
        { // Iterate over weights
            if (weights[i - 1] <= w){           // Check if the item can fit in the current weight
                dp[i][w] = max(dp[i - 1][w],                  
                               dp[i - 1][w - weights[i - 1]] +values[i - 1]);
            }
            else{
                dp[i][w] = dp[i - 1][w]; 
            }
        }
    }

    // The maximum value will be in dp[n][W]
    cout<<dp[n][W];

    return 0;
}
