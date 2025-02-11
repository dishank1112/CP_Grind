#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include<queue>

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
    ll n;
    cin >> n;
    // Gimme Logic dude...
}

int getLargestOutlier(vector<int> &nums)
{    int sum_tot = 0;
     int n = nums.size();
    for (int i=0;i<n;i++)
    {
        sum_tot += nums[i];
    }

    int st_off = 1000;
    vector<int> mpp(2001, 0); 
    for (auto p : nums){
        mpp[p + st_off]++;
    }

    int ans = INT_MIN;

    for (auto p : nums){
        int ans_possible = sum_tot - 2 * p;

        if (ans_possible < -1000 || ans_possible > 1000)continue; 
        
        int ind_mp = ans_possible + st_off;

        if (ans_possible == p){
            if (mpp[ind_mp] >= 2){
                ans = max(ans, ans_possible);
            }
        }
        else
        {
            if (mpp[ind_mp] >= 1){
                ans = max(ans, ans_possible);
            }
        }
    }

    return ans;
}

int f(vector<vector<int>>&edges){
    int n = 0;
    for(auto &p : edges){
        n = max(n,max(p[0],p[1]));
    }
    return n+1;
}

vector<vector<int>> f2(vector<vector<int>>&edges,int n){
    vector<vector<int>> adj(n);
    for ( auto &p : edges){
        adj[p[0]].push_back(p[1]);
        adj[p[1]].push_back(p[0]);
    }
    return adj;
}

vector<int> f3(int n, const vector<vector<int>> &adj, int k){
    vector<int> arr(n, 0);
    for (int i = 0; i < n; ++i){
        vector<int> dis(n, -1);
        queue<int> q;
        q.push(i);
        dis[i] = 0;
        arr[i]++;
        
        while (!q.empty()){
            int node = q.front();
            q.pop();
            int curr = dis[node];
            for (auto it : adj[node])
                if (dis[it] == -1 && curr + 1 <= k){
                    dis[it] = curr + 1;
                    arr[i]++;
                    q.push(it);
            }
        }
    }
    return arr;
}

int f4(vector<int>&arr){
    for(int i=0;i<arr.size();i++){
        int maxi = -1e6;
        maxi = max(arr[i],maxi);
        return maxi;
    }
}

vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2, int k){    
    int n1 = f(edges1);
    int n2 = f(edges2);

    vector<vector<int>> adj1 = f2(edges1,n1);
    vector<vector<int>> adj2= f2(edges2,n2);

    vector<int> goto1 = f3(n1, adj1, k);

    vector<int> goto2;
    if (k - 1 >= 0){
        goto2 = f3(n2, adj2, k - 1);
    }
    else{
        goto2.assign(n2, 0);
    }

    int maxi = 0;
    if (!goto2.empty()) {
        maxi = goto2[0]; 
        for (int i = 1; i < goto2.size(); ++i){
            if (goto2[i] > maxi)
            {
                maxi = goto2[i]; 
            }
        }
    }
        vector<int>ans(n1, 0);
        for (int i = 0; i < n1; ++i)ans[i] = goto1[i] + maxi;
        return ans;
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