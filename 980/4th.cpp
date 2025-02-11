#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define ll long long
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pii>
#define F first
#define S second
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    fast_io();

    #ifndef ONLINE_JUDGE
        freopen("./input.txt", "r", stdin);
        freopen("./output.txt", "w", stdout);
    #endif

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
       vector<ll>arr(n),brr(n);
       rep(i,0,n)cin>>arr[i];
       rep(i,0,n)cin>>brr[i];
       vector<pair<ll,ll>>pairs;
       rep(i,0,n){
        pairs.push_back({arr[i],brr[i]});
       }
       ll ans  = 0;
       ll maxi = -1;
       rep(i,0,n){
        maxi = max(maxi,arr[i]);
       }
        vector<ll>vis(n,-1);

       rep(i,0,n){
          ll val = pairs[i].first;
          ll poss = pairs[i].second;
          
          if(val > pairs[poss].first ){
            if(!vis[i]){
            ans += val;
            vis[i] = 1;
            break;
          }
          }
          else{
             vis[poss] = 1;
             ans += arr[poss];
          }
       }
       cout<<max(ans,maxi)<<endl;
    }

    return 0;
}