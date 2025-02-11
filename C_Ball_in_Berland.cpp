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
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    fast_io();


    ll t;
    cin >> t;
    while (t--) {
        int a,b,k;
        cin >> a>>b>>k;
        vector<int>bo(k);
        vector<int>gi(k);
        vector<int>cnt1(a+1),cnt2(b+1);

        rep(i,0,k){
            cin>>bo[i];
            cnt1[bo[i]]++;
        }
        rep(i,0,k){
            cin>>gi[i];
            cnt2[gi[i]]++;
        }

     ll ans  = 0;
     for(int i=0;i<k;i++){
         ans += k - (cnt1[bo[i]] + cnt2[gi[i]]) +1;
     }
     cout<<ans/2<<endl;
    
    }

    return 0;
}