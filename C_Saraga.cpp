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
long long dp1[3][3], dp2[3][3],ans=1e18;
int start;
long long minCost(int n, vector<vector<int>> &cost){
    int k = n / 2;
    vector<vector<int>> arr;
    arr.resize(k);
    for (int i = 0; i < k; ++i){
        arr[i] = cost[i];
    }
  
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            dp1[i][j] = 1e18;
        }
    }
    start = 0;
    int end = n - 1;
    for (int ind1 = 0; ind1 < 3; ++ind1){
        for (int ind2 = 0; ind2 < 3; ++ind2){
            if (ind1 != ind2){
            dp1[ind1][ind2] = (long long)cost[start][ind1] + (long long)cost[end][ind2];
            }
        }
    }
    for (int ind = 1; ind < k; ++ind){
        start = ind;
        end = n - 1 - ind;
        for (int k = 0; k < 3; ++k){
            for (int l = 0; l < 3; ++l){
                dp2[k][l] = 1e18;
            }
        }
        for (int ind1 = 0; ind1 < 3; ++ind1)
        {
            for (int ind2 = 0; ind2 < 3; ++ind2)
            {
                if (dp1[ind1][ind2] == 1e18)
                {
                    continue;
                }
                for (int i = 0; i < 3; ++i){
                    for (int j = 0; j < 3; ++j){
                        if (i != j && i != ind1 && j != ind2){
                            dp2[i][j] = min(dp2[i][j], dp1[ind1][ind2] + (long long)cost[start][i] + (long long)cost[end][j]);
                        }
                    }
                }
            }
        }
        for (int c1 = 0; c1 < 3; ++c1){
            for (int c2 = 0; c2 < 3; ++c2){
                dp1[c1][c2] = dp2[c1][c2];
            }
        }
    }
   
    for (int ind1 = 0; ind1 < 3; ++ind1){
        for (int ind2 = 0; ind2 < 3; ++ind2){
            if (dp1[ind1][ind2] < ans)
            {
                ans = dp1[ind1][ind2];
            }
        }
    }
    return ans;
}

void solve() {
    string s;
    string t;
    cin>>s>>t;
    
    ll n = s.size();
    ll m = t.size();
    if(n==1 || m == 1){
        cout<<-1<<endl;
        return ;
    }
    unordered_map<char,ll>mp;
    for(ll i=0;i<n;i++){
        if(n>2 && mp.find(s[i]) != mp.end()){
            continue;
        }
        mp[s[i]] = i;
    }
    string ans  ="";
    ll ind  = -1;
    for(ll i=m-2;i>=0;i--){
      if(mp.find(t[i]) != mp.end() && mp[t[i]] > 0){
        ans = ans + t[i];
        ind  = mp[t[i]];
        break;
      }
      else ans += t[i];
    }
    if(ind  == -1){
        cout<<-1<<endl;
        return;
    }
    for(ll i=ind-1;i>=0;i--){
     ans += s[i];
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<t[m-1]<<endl;
}

int main() {
    fast_io();
     solve();
    
    return 0;
}