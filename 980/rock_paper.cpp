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


int f(string str, int ind,char prev,vector<vector<int>>&dp){
         if(ind >= str.size())return 0;
         char ch = str[ind];
         int ans = 0;
         
         if(dp[ind][ch] != -1)return dp[ind][ch];

         if(ch == 'R'){
              if(prev == 'P'){
                ans = 0 + f(str,ind+1,'R',dp);
              }
              else{
                  ans = max(f(str, ind + 1, 'R', dp), 1 + f(str, ind + 1, 'P', dp));
              }
         }
         if (ch == 'S')
         {
             if (prev == 'R')
             {
                 ans = 0 + f(str, ind + 1, 'S', dp);
             }
             else
             {
                 ans = max(f(str, ind + 1, 'S', dp), 1 + f(str, ind + 1, 'R', dp));
             }
         }
         if (ch == 'P')
         {
             if (prev == 'S')
             {
                 ans = 0 + f(str, ind + 1, 'P', dp);
             }
             else
             {
                 ans = max(f(str, ind + 1, 'P', dp), 1 + f(str, ind + 1, 'S', dp));
             }
         }
         return dp[ind][ch] = ans;
}




int main() {
    fast_io();

    #ifndef ONLINE_JUDGE
        freopen("./input.txt", "r", stdin);
        freopen("./output.txt", "w", stdout);
    #endif
    
    string str;
    cin>>str;
    vector<vector<int>>dp(str.size()+1,vector<int>(3,-1));
    cout<<f(str,0,'-1',dp)<<endl;

    return 0;
}