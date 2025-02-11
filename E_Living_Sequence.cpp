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

bool f(int n){
   string str = to_string(n);
   int cnt = 0;
   int ans  = 0;
   for(int i=0;i<str.size();i++){
    int dig = str[i] - '0';
    if(dig <= 4)cnt  = dig;
    else cnt  = dig-1;
    cnt  = cnt*pow(9,str.size()-i-1);
    ans += cnt;
    if(str[i] == '4'){
        break;
    }
    if(i == str.size()-1){
        ans++;
    }
   }
   return ans-1;
}












void solve() {
    int k;
    cin >> k;
    
    int lo = k;
    int hi = 100*k;
    long long ans  = k;
    while(lo <= hi){
        long long  m = lo + (hi-lo)/2;
        if(f(m) >= k){
            ans  = m;
            hi = m-1;
        }
        else lo = m+1;
    }
   cout<<ans<<"\n";
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