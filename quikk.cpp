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


int partition(int low, int high,vector<int> &arr){
     int pivot = arr[low];
    int cnt  = 0;
     for(int i=low+1;i<=high;i++){
          if(arr[i] <= pivot)cnt++;
     }
     int pivot_ind  = low+cnt;
     swap(arr[low],arr[low+cnt]);

     int left = low;
     int right  = high;
     while(left<pivot_ind && right > pivot_ind && left < right){
           while(arr[left] < pivot)left++;
           while(arr[right] > pivot)right--;
           if(left < right)swap(arr[left],arr[right]);
           left++;
           right--;
     }
     return pivot_ind;

}


void quicksort(int low,int high,vector<int>&arr){
    if(low >= high)return ;
     int pivot = partition(low,high,arr);
     quicksort(low,pivot-1,arr);
     quicksort(pivot+1,high,arr);
}


void solve() {
      int n;
      cin>>n;
      vector<int>arr(n);
      
    for(int i=0;i<n;i++)cin>>arr[i];
      quicksort(0,n-1,arr);
      for(auto p : arr)cout<<p<<" ";
      cout<<endl;
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