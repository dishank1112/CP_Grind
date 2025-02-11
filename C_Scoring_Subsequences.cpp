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

    // #ifndef ONLINE_JUDGE
    //     freopen("./input.txt", "r", stdin);
    //     freopen("./output.txt", "w", stdout);
    // #endif

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll>arr(n);
        for(ll i = 0;i<n;i++)cin>>arr[i];
        int cnt  = 1;
        cout<<1<<" ";

        for(ll i = 1;i<n;i++){
            if(arr[i-cnt] >= cnt+1){
                cnt++;
            }
            cout<<cnt<<" ";
        }
        cout<<endl;
    }

    return 0;
}