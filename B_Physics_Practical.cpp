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


int f(int i,int j,vector<int>&arr,vector<vector<int>>&dp){
    if(i >= j)return 0;
    if(arr[j] <= 2*arr[i])return 0;
    if(dp[i][j] != -1)return dp[i][j];
     int ans  = 0;
    if(arr[j] >= 2*arr[i]){
       ans  = 1 + min(f(i+1,j,arr,dp),f(i,j-1,arr,dp));
    }
    return ans;
}

void solve() {
    int n;
    cin>>n;
    vector<int>arr(n);
    read(arr);

    sort(all(arr));
     int i = 0;
     int j = 0;
     int ans  = 0;
     while(j<n){
       if(arr[i]*2>=arr[j]){
        ans  =  max(ans,j-i+1);
        j++;
     }
     else i++;
    }
    cout<<n-ans<<endl;
}

int gcd(int a, int b){
    if(a == 0)return b;
    else return gcd(b%a,a);
}

vector<vector<int>> sortMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();
    for (int j = 0; j < n; j++)
    {
        vector<int> temp;
        vector<pair<int, int>> temp2;
        for (int i = 0, k = j; i < n && k < n; i++, k++)
        {
            temp.push_back(grid[i][k]);
            temp2.push_back({i, k});
        }

        if (j == 0){
            sort(temp.begin(), temp.end(), greater<int>());
        }
        else{
            sort(temp.begin(), temp.end());
        }

        for (int p = 0; p < temp.size(); p++)
        {
            grid[temp2[p].first][temp2[p].second] = temp[p];
        }
    }

    for (int i = 1; i < n; i++)
    {
        vector<int> temp;
        vector<pair<int, int>> temp2;
        for (int k = i, j = 0; k < n && j < n; k++, j++)
        {
            temp.push_back(grid[k][j]);
            temp2.push_back({k, j});
        }
        sort(temp.begin(), temp.end(), greater<int>());
        for (int p = 0; p < temp.size(); p++)
        {
            grid[temp2[p].first][temp2[p].second] = temp[p];
        }
    }

    return grid;
}

int main() {
    fast_io();
    
        solve();
    
    return 0;
}