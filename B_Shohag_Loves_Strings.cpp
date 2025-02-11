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

void solve()
{
    int n;
    string s;
    cin >> s;
    n = s.size();
    string ans = "";
    for (int i = 0; i < n; i++)
    { // Correctly structured loop
        if (i + 1 < n && ans.empty())
        { // This condition checks if ans is still empty
            if (i + 1 < n && s[i] == s[i + 1])
            {
                ans = s.substr(i, 3); // Get a substring of length 3
            }
            else if (i + 2 < n && s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i + 2])
            {
                ans = s.substr(i, 3);
            }
 // well hello there i am Jiraya u can send love letters later its really nuc eto meet ya!!

        }
    }
    if (ans.empty())
        cout << -1 << "\n";
    else
        cout << ans << "\n";
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