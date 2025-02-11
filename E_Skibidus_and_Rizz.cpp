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
// well Hello There I am Jiraya U can send love letters k
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
// Well Hello there I a
void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    if(max(n-m,m-n) > k){
        cout<<-1<<"\n";
        return ;
    }
    
    int size = n+m;
    string ans="";
    if(k == 1){
        if(n>m){
            for(int i=0;i<size;i++){
                if(i%2==0){
                    cout<<'0';
                }
                else cout<<'1';
            }
            cout<<endl;
            return ;
        }
        else if (m>n)
        {
            for (int i = 0; i < size; i++)
            {
                if (i % 2 == 0)
                {
                    cout << '1';
                }
                else
                    cout << '0';
            }
            cout << endl;
            return;
        }
    }
    if(n>m){
        int i=0;
        for(i=0;i<size;){
         int cnt  = 0;
         while(cnt<k && i<size && n>0){
            ans+='0';
            cnt++;
            i++;
            n--;
         }
          if(m>0 && i<size){
            ans+='1';
            m--;
            i++;
          }
          if(n>0 && i<size){
            ans+='0';
            n--;
            i++;
          }
          if (m > 0 && i < size)
          {
              ans += '1';
              m--;
              i++;
          }
        }
        while(i<size){
            if(n != 0){
          while(n != 0){
            ans+='0';
            n--;
            i++;
          }
        }
        else if(m != 0){
            while(m != 0){
                ans+='1';
                m--;
                i++;
            }
        }
        }
    }
    else if (m>n)
    {
        int i = 0;
        for (i = 0; i < size;)
        {
            int cnt = 0;
            while (cnt < k && i < size && m > 0){
                ans += '1';
                cnt++;
                i++;
                m--;
            }
            if (n > 0 && i < size){
                ans += '0';
                n--;
                i++;
            }
            if (m > 0 && i < size)
            {
                ans += '1';
                m--;
                i++;
            }
            if (n > 0 && i < size)
            {
                ans += '0';
                n--;
                i++;
            }
        }
        while (i < size)
        {
            if (m != 0)
            {
                while (m != 0)
                {
                    ans += '1';
                    m--;
                    i++;
                }
            }
            else if (n != 0)
            {
                while (n != 0)
                {
                    ans += '0';
                    n--;
                    i++;
                }
            }
        }
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