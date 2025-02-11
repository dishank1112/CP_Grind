#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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


vector<int> f(vector<ll>&arr,int ind){
    vector<int>temp;
    for(int i=0;i<=ind;i++){
      temp.push_back(arr[i]);
    }
    sort(temp.rbegin(),temp.rend());
    return temp;
}




int main() {
    fast_io();

    ll n,h;
    cin>>n>>h;
    vector<ll>arr(n);
    rep(i,0,n)cin>>arr[i];
    ll ans  = 0;
    ll p = h;
    rep(i,0,n){
         vector<int>temp= f(arr,i);
         int j = 0;
       for(j=0;j<=i;j+=2){
           if(h >= temp[j]){
              h = h - temp[j];
           }
           else break;
       }

       if(j >= i+1)ans  = i+1; 
       h = p;
    }
    cout<<ans<<endl;

    return 0;
}