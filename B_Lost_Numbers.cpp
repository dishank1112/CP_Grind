#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <string>

using namespace std;

#define ll long long
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pii>
#define F first
#define S second
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

template <typename T>
void read(vector<T> &arr) {
    for (auto &x : arr) {
        cin >> x;
    }
}

// int f(int ind,vector<int>&arr1,vector<int>&arr2,int pick1){
//       if(ind >= arr1.size() || ind >= arr2.size()){
//         return 0;
//       }
//       int ans  = 0;

//     if(pick1 == 1){
//       ans = max(arr1[ind] + f(ind+1,arr1,arr2,0), 0 + f(ind+1,arr1,arr2,1));
//     }
//     else ans = max(arr2[ind] + f(ind+1,arr1,arr2,1),0 + f(ind+1,arr1,arr2,0));
//     return ans;
// }



void solve() {
    ll n;
    cin>>n;
    vector<ll>arr1(n);
    vector<ll>arr2(n);
    read(arr1);
    read(arr2);
    
    // cout<<max(arr1[0] + f(1,arr1,arr2,0), arr2[0] + f(1,arr1,arr2,1));

    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));

    dp[n][0] = 0;
    dp[n][1] = 0;

    for (ll ind = n - 1; ind >= 0; ind--)
    {
        dp[ind][0] = max(arr1[ind] + dp[ind + 1][1], dp[ind + 1][0]);

        dp[ind][1] = max(arr2[ind] + dp[ind + 1][0], dp[ind + 1][1]);
    }

    cout << max(dp[0][0], dp[0][1]);
}

int main() {
    fast_io();
        solve();
    

    return 0;
}