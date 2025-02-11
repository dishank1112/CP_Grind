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
     vector<int>arr(n);
     read(arr);
     int cnt = 0;
     for(int i=0;i<n;i++){
        if(arr[i] == 0)cnt++;
     }
     if(cnt == arr.size()){
        cout<<0<<'\n';
        return ;
     }
     else cnt  = 0;

     for(int i=0;i<n;i++){
        sort(arr.begin(), arr.end());
         if (arr[i] == 0)
         {
             continue;
        }
        int ind = arr[i];
        int mid_ind = (arr.size()+ind-1)/2;
        int x = arr[mid_ind];
        for(int j=mid_ind;j<arr.size();j++){
            arr[j] -= x;
        }
        cnt++;
        if(arr[arr.size()-1] == 0)break;
     }
     cout<<cnt<<'\n';
     
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