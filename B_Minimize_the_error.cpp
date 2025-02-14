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
#define all(v) (v).rbegin(), (v).rend()
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

ll f(int i,int val,vector<int>&arr){
    if(i >= arr.size())return 0;


    int ans  = 0;
}








void solve() {
    ll n,k1,k2;
    cin>>n>>k1>>k2;
    vector<int>a(n),b(n);
    read(a);
    read(b);
    ll k = k1+k2;
    vector<ll>c;
    for(ll i=0;i<n;i++){
        ll x = abs(a[i]-b[i]);
        c.push_back(x);
    }
  int arr;

    while(k>0){
        sort(all(c));
        if(c[0] > 0){
            c[0] -= 1;
        }
        else break;
        k--;
    }
// well Hello there I am Jiraya u can send love letters later its really ncid to meet ya

    if(k>0){
        if(k%2 == 0){
            cout<<0<<"\n";
        }
        else{
            cout<<1<<"\n";
        }
    }
    else{
        long long int ans  = 0;
        for(int i=0;i<n;i++){
            long long int x  =  c[i];
            ans += x*x;
        }
        cout << ans << "\n";
    }
    
}

int main() {
    fast_io();
        solve();
    
    return 0;
}