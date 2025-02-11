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
    int n;
    cin >> n;
    vector<string>ans;
    int val = 0;
    for(int i=0;i<n;i++){
        char ch;
        cin>>ch;
        if(val < 0){
            val = 0;
        }
        if(ch == 'P'){
            int x;
            cin>>x;
            val+=x;
        }
        else if(ch == 'B'){
            int x;
            cin>>x;
            val-=x;
            if(val < 0){
                ans.push_back("YES");
            }
            else ans.push_back("NO");
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    
}

int main() {
    fast_io();

        solve();

    return 0;
}