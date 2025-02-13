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


void solve() {
    ll n,k;
    cin>>n>>k;
    ll rev = n;
    ll p = 0;
    for(ll i=1;i<=n;i++){
        p+=abs(rev-i);
        rev--;
    }
    if(k%2 != 0 || k > p){
        cout<<"No"<<endl;
        return;
    }
    else{
    cout<<"Yes"<<endl;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++)arr[i] = i+1;
    ll x=1;
    ll y=n;
    
    while(x<=y){
        if(2*(y-x) <= k){
            k = k -2*(y-x);
            swap(arr[x-1],arr[y-1]);
            x++;
            y--;
        }
        else y--;
    }
    for(ll i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return ;
    }
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