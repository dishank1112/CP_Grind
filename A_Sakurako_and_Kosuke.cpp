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
#define rep(i, a, b) for (ll i = a; i < b; i++)
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
   vector<ll>arr(n);
   rep(i,0,n)cin>>arr[i];
   
   sort(all(arr));

   ll ans  = n;
   ll l = 1;
   ll r = n;


   while (l <= r) {
           ll m = r+(l - r)/2;

        bool flag = false;

        if (m == 1) {
            ans = min(ans, n - 1);
            l = m + 1;
            continue;
        }

        for (ll i = 0; i + m - 1 < n; i++) { 
            if (arr[i] + arr[i + 1] > arr[i + m - 1]){
                flag = true;
                break;
            }
        }

        if (flag) {
            ans = min(ans, n - m);
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

   cout << ans << endl;
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














// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// void solve() {
//     int n;
//     cin >> n;

//     vector<long long> a(n);
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//     }

//     // Sort the array
//     sort(a.begin(), a.end());

//     int ans = n;
//     int l = 1, r = n;

//     while (l <= r) {
//         int mid = (l + r) / 2;
//         bool found = false;

//         // Special case for single element
//         if (mid == 1) {
//             ans = min(ans, n - 1);
//             l = mid + 1;
//             continue;
//         }

//         // Check if we can form triangles with mid-sized subsequences
//         for (int i = 0; i + mid - 1 < n; i++) {
//             long long x = a[i] + a[i + 1];
//             if (x > a[i + mid - 1]) {
//                 found = true;
//                 break;
//             }
//         }

//         // Update answer based on triangle possibility
//         if (found) {
//             ans = min(ans, n - mid);
//             l = mid + 1;
//         } else {
//             r = mid - 1;
//         }
//     }

//     cout << ans << endl;
// }

// int main() {
//     int tests;
//     cin >> tests;

//     while (tests--) {
//         solve();
//     }

//     return 0;
// }
