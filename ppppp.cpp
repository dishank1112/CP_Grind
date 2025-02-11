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
    vector<int> arr(n), ve;
    read(arr);
    unordered_map<int,int>mp;

    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    int maxi = 1;

    for(auto it : mp){
        if(it.second > maxi){
            maxi = it.second;
        }
    }
    cout<<n-maxi<<"\n";
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