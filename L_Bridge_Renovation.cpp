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

void solve() {
    ll n;
    cin >> n;
    int n18 = n;
    int n21 = n;
    int n25 = n;
    int ans  = 0;
    while(n18 > 0 && n21 > 0){
        if (n21 == 1){
            n21 -=1;
            n18-=2;
        }
        else {
       n21-=2;
       n18-=1;
        }
       ans++;
    }


    ans += n25/2 + (n25%2);

    if(n18%3  == 1 || n18%3 == 2){
        ans += n18/3 + 1;
    }
    else ans += n18/3;
    cout<<ans<<"\n";
}

int main() {
    fast_io();

        solve();

    return 0;
}