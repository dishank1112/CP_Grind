#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

#define ll long long
#define pb push_back
#define all(v) (v).begin(), (v).end()

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
    int n;
    cin >> n;

    // The logic for selecting nodes and interacting with the device:
    // We start by querying a set of nodes. We can try to pick the first few nodes
    // and get feedback from the device.

    vector<int> nodes_to_query;
    for (int i = 1; i <= n; i++)
    {
        nodes_to_query.push_back(i);
    }

    // Query the device with all nodes. This is just a placeholder for a real query logic.
    cout << "? " << n << " ";
    for (int i = 0; i < n; i++)
    {
        cout << nodes_to_query[i] << " ";
    }
    cout << endl;
    cout.flush();

    int max_gcd;
    cin >> max_gcd;

    // Now, based on the response, we would refine our search for the nodes that might give
    // the maximum GCD.

    // For now, let's just simulate returning two nodes.
    cout << "! " << 1 << " " << n << endl;
    cout.flush();
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
// D. Hemose in ICPC codeforces github solution