#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
// well hello there I am jiraya u can send love letters later its 

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

// well hello 
template <typename T>
void read(vector<T> &arr) {
    for (auto &x : arr) {
        cin >> x;
    }
}

void solve() {
    int n;
    cin >> n;
    
}
vector<vector<long long>> dp;

long long f(int K, int n,vector<int>&arr,vector<vector<long long>>dp,int mask, int curr_energy){
    if (mask == (1 << n) - 1)return 0;
    long long ans = LLONG_MAX;
    if (dp[mask][curr_energy] != -1)return dp[mask][curr_energy];

    for (int i = 0; i < n; ++i){
        if ((mask & (1 << i)) == 0){
            int p = curr_energy + K;
            long long temm = ((arr[i] + curr_energy - 1) / curr_energy) + f(n, K, arr, dp, mask | (1 << i), p);
            ans = min(ans, temm);
        }
    }
    return dp[mask][curr_energy] = ans;
}

int findMinimumTime(vector<int> &arr, int K){
    int n = arr.size();
    dp.assign(1 << n, vector<long long>(100, -1));
    long long answer = f(n,K,arr,dp,0, 1);
    return (answer <= 1e12) ? (int)answer : -1;
}

int main() {
    fast_io();

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}