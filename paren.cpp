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

int main()
{
    fast_io();
    int t;
    cin >> t;
    while (t--){
        string s = "((()())())";
        int n = s.size();
        int cnt1 = 0;
        for(int i=0;i<n;i++){
            if(s[i] ='(')cnt1++;
            else cnt1--;
            if(cnt1< 0){
                cout<<"False";
                break;
            }
        }
        if(cnt1 == 0)cout<<"True";
        else cout<<"False";
    }
    return 0;
}