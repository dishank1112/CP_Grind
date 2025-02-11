#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <queue>
#include <stack>

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
void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> s, t;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        int x = 1e9; 
        int y = 1e9; 
        if (!s.empty())x = s.back();
        if (!t.empty())y = t.back();

        if (x <= y){
            if (arr[i] <= x || arr[i] > y)s.push_back(arr[i]);
            else  t.push_back(arr[i]);
        }
        else{
           if(arr[i] <= y || arr[i] > x)t.push_back(arr[i]);
           else s.push_back(arr[i]); 
        }
    }
    if (n <= 2){
        cout << 0 << endl;
        return;
    }

    int ans = 0;

    // Count increasing pairs in `s`
    for (int i = 0; i < (int)s.size() - 1; i++)
    {
        if (s[i] < s[i + 1])
            ans++;
    }

    // Count increasing pairs in `t`
    for (int i = 0; i < (int)t.size() - 1; i++)
    {
        if (t[i] < t[i + 1])
            ans++;
    }

    cout << ans << endl;
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

// we/ll Hellothere I am 