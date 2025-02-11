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

template <typename T>
void read(vector<T> &arr) {
    for (auto &x : arr) {
        cin >> x;
    }
}


void solve() {
    ll n,m;
    cin>>n>>m;
    struct Compare
    {
        bool operator()(const pair<ll, vector<ll>> &a, const pair<ll, vector<ll>> &b)
        {
            return a.first < b.first; 
        }
    };

    priority_queue<pair<ll, vector<ll>>, vector<pair<ll, vector<ll>>>, Compare> pq;

    for(ll i=0;i<n;i++){
        ll sum = 0;
        vector<ll>temp(m);
        for(ll i=0;i<m;i++){
           cin>>temp[i];
           sum= sum+temp[i];
        }
        pq.push({sum,temp});
    }
    vector<ll>arr;
    while(!pq.empty()){
        auto vec = pq.top().second;
        for(auto p : vec){
            arr.push_back(p);
        }
        pq.pop();
    }
    // well Hello there I am JIraya U can send 
    ll ans  = 0;
    ll sum = 0;
    for(int i=0;i<n*m;i++){
        sum+=arr[i];
        ans+=sum;
    }
    cout<<ans<<endl;
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
