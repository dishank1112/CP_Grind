
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

    for (int h : arr){
     int pos = -1;
     for (int i = 0; i < ve.size(); i++)
     {
         if (ve[i] > h){
             pos = i;
             break;
         }
     }

     if (pos == -1)ve.push_back(h);
     else ve[pos] = h;
    }

    cout << n - ve.size() << endl;
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
