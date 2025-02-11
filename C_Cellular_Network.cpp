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

bool f(ll rad, vector<ll> &arr, vector<ll> &brr)
{
    int n = arr.size();
    int m = brr.size();
    int cnt = 0; // Counts how many cities are covered
    int ind = 0; // Tracks the current city being checked

    for (int i = 0; i < m; i++)
    {
        int range1 = brr[i] - rad;
        int range2 = brr[i] + rad;

        // Check if the city at arr[ind] is within range of the current tower
        while (ind < n && arr[ind] >= range1 && arr[ind] <= range2)
        {
            cnt++;
            ind++;
        }

        // If all cities are covered, return true
        if (cnt == n)
        {
            return true;
        }
    }

    // If not all cities are covered by the time we finish the loop
    return false;
}

void solve() {
    ll n,m;
    cin >> n>>m;
    vector<ll>arr(n);
    vector<ll>brr(m);
    read(arr);
    read(brr);
    
    sort(all(arr));
    sort(all(brr));

    ll hi = max(abs(arr[0] - brr[m - 1]), abs(arr[n - 1] - brr[0]));

    ll lo = 0;
    ll ans  = hi;
    while(lo <= hi){
        ll mid = lo + (hi-lo)/2;
        if(f(mid,arr,brr)){
            ans  = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    cout<<ans<<"\n";
}

int main() {
    fast_io();

        solve();

    return 0;
}