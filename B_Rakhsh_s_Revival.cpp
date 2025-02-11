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
void read(string &str)
{
    cin>>str;
}

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;

    string str;
    read(str);

    ll ans = 0;
    ll i = 0;

    while (i < n){
            ll cnt  = 0;
            while(i<n && str[i] == '0'){
                cnt++;
                i++;
          if(cnt  == m){
            ans++;
            i=i+k-1;
            break;
          }
        }       
        if(cnt < m)i++;
    }
    cout << ans << endl;
    return ;
}

int main()
{
    fast_io();

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
