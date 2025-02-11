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

void solve(){
    ll n, b, c;
    cin >> n >> b >> c;
    if(c >= n){
        cout<<n<<"\n";
        return ;
    }
    if(b == 0){
        if(c >= n-2){
            cout<<n-1<<"\n";
            return ;
        }
        else{
            cout<<-1<<endl;
            return ;
        }
    }
    cout<<n-max(0LL,1+ (n-c-1)/b)<<"\n";
}
//Well Hello there i am Jiraya u can send love letters later
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