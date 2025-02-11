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
    int n;
    cin >> n;

// well hello there I am jiraya u can send love letters later its really nice to meet ya!!\
// well jelo there i am jiraay u ca send love letters latwr its 

    vector<int>ans(n);
    ans[0] = 2;
    int done  = 1;
    int dig = 2;
    for(int i=1;i<n;i++){
        while(dig%(i+1) != done){
           dig++;
        }
        if(dig%(i+1) == done){
            ans[i] = dig;
            done++;
        }
    }
    for(auto p : ans)cout<<p<<" ";
    cout<<endl;
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