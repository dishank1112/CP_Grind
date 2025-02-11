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

int main() {
    fast_io();

    // #ifndef ONLINE_JUDGE
    //     freopen("./input.txt", "r", stdin);
    //     freopen("./output.txt", "w", stdout);
    // #endif

    string t;
    cin>>t;
    int n = t.size();
    rep(i,1,n){
       if(t[i] == t[i-1]){
          char ch = t[i];
          if (t[i] != 'a' && (i + 1 > n || t[i + 1] != 'a'))
          {
              t[i] = 'a';
          }
          else if(t[i] != 'a' && t[i+1] == 'a'){
                if(t[i] != 'b'){
                    t[i] = 'b';
                }
                else t[i] = 'c';
          }
          else if(t[i] == 'a' && (i+1 > n || t[i+1] != 'b')){
                  t[i] = 'b';
          }
          else if(t[i] == 'a' && t[i+1] == 'b'){
            t[i] = 'c';
          }
       }
       
       else continue;
    }

    cout<<t<<endl;
    
    return 0;
}