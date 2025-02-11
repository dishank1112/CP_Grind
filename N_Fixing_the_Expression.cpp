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
    string str;
    cin>>str;
    
    int n1 = str[0] - '0';
    int n2 = str[2] - '0';
    char symb = str[1] - '0';

    if (n1 > n2)
    {
        cout << to_string(n1) + ">" + to_string(n2);
    }
    else if (n1 < n2)
    {
        cout << to_string(n1) + "<" + to_string(n2);
    }
    else if (n1 == n2)
    {
        cout << to_string(n1) + "=" + to_string(n2);
    }
    cout<<endl;
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