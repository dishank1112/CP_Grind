#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <queue>
#include <stack>

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
// well Hello There 
int mod = 1e9+7;
int dp[2005][2005];

int f(int i, int k, int n){
    if(k<=0)return 1;
    if(dp[i][k] != -1)return dp[i][k];
    int ans=0;
    for(int j=i;j<=n;j+=i){
         if(j%i == 0){
            ans = (ans + f(j,k-1,n))%mod;
            ans  = ans%mod;
         }
    }
     dp[i][k] = ans;
     return dp[i][k];
}

void solve() {
   int n,k;
   cin>>n>>k;
   memset(dp,sizeof(dp),-1);
   cout<<f(1,k,n)<<"\n";
}

int main() {
    fast_io();
    solve();   
    return 0;
}