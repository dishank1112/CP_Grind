#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define pb push_back

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
    vector<pair<int, int>> arr(n);

    for (int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    if (n == 1){
        cout << 1 << endl; 
        return;
    }
     vector<int>dp(n);                       
    int last_fell_position = arr[0].first;
     dp[0] = 1;
    for (int i = 1; i < n - 1; i++){
        int x = arr[i].first, h = arr[i].second;
        if (x - h > last_fell_position){
            last_fell_position = x; 
            dp[i] = 1 + dp[i-1];
        }
        else if (x + h < arr[i + 1].first){
            last_fell_position = x + h; 
            dp[i] = 1 + dp[i-1];
        }
        else{
            last_fell_position = x;
            dp[i] = dp[i-1];
        }
    }

    cout << 1+dp[n-2] << endl;
}

int main()
{
    fast_io();
    solve();
    return 0;
}
