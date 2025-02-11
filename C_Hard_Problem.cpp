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


void solve()
{
    
        ll m, a, b, c;
        cin >> m >> a >> b >> c;

        long long oness = min(m, a);

        long long twos = min(m, b);
        long long rem1 = m - oness;
        long long rem2 = m - twos;

        long long threes = min(rem1, c); 
        c -= threes;                               

        threes += min(rem2, c);

        long long ans = oness + twos + threes;

        cout << ans << endl;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}