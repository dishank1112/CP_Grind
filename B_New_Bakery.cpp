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
    ll n,a,b;
    cin>>n>>a>>b;
    if(a>=b){
        cout<<n*a<<endl;
        return ;
    }
    else{
        ll c = b-a;
        if(c>=n){
            ll ans  =  n*b-((n-1)*(n)/2);
            cout<<ans<<endl;
            return ;
        }
        ll ans = c*b+(n-c)*a -((c-1)*(c)/2);
        cout<<ans<<endl;
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