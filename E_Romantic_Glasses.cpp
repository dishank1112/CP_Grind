#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include<map>

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
#define per(i, a, b) for (ll i = b - 1; i >= a; i--)

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){
    ll n;
    cin>>n;
    vector<ll>arr(n);
    rep(i,0,n){
        cin>>arr[i];
    }
    ll sum = 0;
    map<ll,ll>mp;
    mp[0] = 1;

    rep(i,0,n){
        arr[i] *= i%2==0 ? -1 : 1;
         sum += arr[i];
         if(mp[sum]){
            cout<<"YES"<<endl;
            return ;
         }
         ++mp[sum]; 
    }
    cout<<"NO"<<endl;
    return ;
}

int main() {
    fast_io();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}