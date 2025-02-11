#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define ll long long
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool possible(vector<ll> &v1, vector<ll> &v2, vector<ll> &op)
{
    map<ll, ll> op_count; // Count the frequency of each operation value
    for (ll x : op)
        op_count[x]++;

    for (ll i = 0; i < v1.size(); i++)
    {
        if (v1[i] == v2[i])
            continue; // Already matching, no need to change

        // If we need to change v1[i] to v2[i], check if we have a suitable operation
        if (v1[i] > v2[i] || op_count[v2[i]] == 0)
        {
            return false; // Not possible to reduce or we don't have the required op
        }
        else
        {
            op_count[v2[i]]--; // Use one occurrence of this operation
        }
    }
    return true;
}

int main()
{
    fast_io();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        vector<ll> v1(n);
        vector<ll> v2(n);

        rep(i, 0, n) cin >> v1[i];
        rep(i, 0, n) cin >> v2[i];

        ll m;
        cin >> m;

        vector<ll> op(m);
        rep(i, 0, m) cin >> op[i];

        if (possible(v1, v2, op))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
