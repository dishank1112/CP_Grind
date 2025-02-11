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

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

template <typename T>
void read(vector<T> &arr)
{
    for (auto &x : arr)
    {
        cin >> x;
    }
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> A(n), B(n);
    read(A);
    read(B);

    ll remii = 0;
    rep(i, 0, n)
    {
        if (A[i] < B[i])
        {
            ll diff = B[i] - A[i];

            A[i] += 2 * diff;
            remii += diff;
        }
    }

    rep(i, 0, n){
        A[i] -= remii;
        if (A[i] < 0 || A[i] < B[i]){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main()
{
    fast_io();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
