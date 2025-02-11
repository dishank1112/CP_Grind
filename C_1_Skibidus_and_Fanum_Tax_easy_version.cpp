#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void read(vector<T> &arr)
{
    for (auto &x : arr)
    {
        cin >> x;
    }
}

void solve()
{
    int n, m;
    cin >> n >> m; 
    vector<int> a(n);
    vector<int> lefttt(n), rightt(n);
    vector<vector<bool>> dp(n, vector<bool>(2, false));
    read(a);
    int b;
    cin >> b;

    for (int i = 0; i < n; i++){
        lefttt[i] = min(a[i], b - a[i]);
        rightt[i] = max(a[i], b - a[i]);
    }

    dp[0][0] = true;
    dp[0][1] = true;

    for (int i = 1; i < n; i++){
        for (int vall = 0; vall < 2; vall++){
            if (!dp[i - 1][vall])continue;
            int prev = (vall == 0 ? lefttt[i - 1] : rightt[i - 1]);
            if (prev <= rightt[i])
                dp[i][1] = true;
            if (prev <= lefttt[i])dp[i][0] = true;
        }
    }
    if(dp[n-1][0] || dp[n-1][1]){
        cout<<"YES"<<endl;
        return ;
    }
    cout<<"NO"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
