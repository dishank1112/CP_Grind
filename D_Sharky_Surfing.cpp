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
#define pii pair<ll, ll>
#define vi vector<ll>
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



int f(vpii hurdles, vpii powerss){
    
    ll ans = 0;
    multiset<ll> multi_st;
    reverse(all(powerss));
    ll tot = 1;
    for (auto &hurdle : hurdles){
        ll left = hurdle.F;
        ll right = hurdle.S;
        ll dis = right-left+2;

        while (!powerss.empty() && powerss.back().F < left){
            multi_st.insert(powerss.back().S);
            powerss.pop_back();
        }

        while (!multi_st.empty() && tot < dis){
            ll max_power = *multi_st.rbegin();
            multi_st.erase(prev(multi_st.end()));
            tot += max_power;
            ans++;
        }
        if (tot < dis){
            ans = -1;
            break;
        }
    }
    return ans;
}










void solve(){
    ll n, m, l;
    cin >> n >> m >> l;

    vpii hurdles(n);
    vpii powerss(m);

    rep(i, 0, n)cin >> hurdles[i].F >> hurdles[i].S;
    
    rep(i, 0, m)cin >> powerss[i].F >> powerss[i].S;
    
    cout << f(hurdles,powerss)<< "\n";
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
