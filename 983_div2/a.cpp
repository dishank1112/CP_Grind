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
#define rep(i, a, b) for (ll i = a; i < b; i++)
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

void solve() {
    ll n;
    cin >> n;
    vector<ll>arr(2*n);
    rep(i,0,2*n)cin>>arr[i];
    
    ll cnt1  = 0;
    ll cnt0 = 0;
    rep(i,0,2*n){
        if(arr[i] == 1 )cnt1++;
        else cnt0++;
    }

    if(2*n == 2){
       if(cnt1 == 0 || cnt1==2){
           cout<<0<<" "<<0<<endl;
       } 
       else{
        cout<<1<<" "<<1<<endl;
       }
       return ;
    }
    
    else{
        ll ans1 = 0;
         ll ans2 = 0;
        if(cnt1 >= n){
           ans2 = cnt0;
        }
        else ans2 = cnt1;
        if(cnt1%2 == 0){
            ans1 = 0;
        }
        else ans1 = 1;
        cout<<ans1<<" "<<ans2<<endl;
    }
    return ;
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