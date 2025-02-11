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

    vector<int>arr;
    int n = arr.size();
    int sum = 0;
    rep(i,0,n){
        sum += arr[i];
    }
    int target = sum/3;

    int s1=0,s2=0,s3=0;
    int p =0;
    for(int i=0;i<n;i++){
        p++;
        if(s1 != target){
            s1 += arr[i];
        }
    }
    for (int i = p; i < n; i++){
        if (s2 != target){
            s2 += arr[i];
        }
    }

    s3 = sum-s1-s2;
    if(s3 == target){
        cout<<"yes";
    }
    else cout<<"No"<<endl;

    return 0;
}