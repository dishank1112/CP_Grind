#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include<unordered_map>

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

int main() {
    fast_io();

    // #ifndef ONLINE_JUDGE
    //     freopen("./input.txt", "r", stdin);
    //     freopen("./output.txt", "w", stdout);
    // #endif

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>>arr(n);
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
           int k;
           cin>>k;
           while(k--){
            int x;
            cin>>x;
            arr[i].push_back(x);
            mp[x]++;
           }
        }
        int ans = 0;
        for(auto bits : arr){
            bool flag = true;
            for(auto bit : bits){
                if(mp[bit] == 1){
                    flag = false;
                    break;
                }
            }
            if(flag == true){
                ans = 1;
                break;
            }
        }
        if(ans == 1)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        
    }

    return 0;
}