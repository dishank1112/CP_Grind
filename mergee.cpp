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

vector<int> merge(int l,int mid, int h,vector<int>&arr){
        vector<int>temp;
        int left  = l;
        int right  = mid+1;

        while(left <=mid && right<=h){
            if(arr[left] < arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }

        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=h){
            temp.push_back(arr[right]);
            right++;
        }
        
        for(int i=l;i<=h;i++){
            arr[i] = temp[i-l];
        }
        return arr;
}




void merge_sort(int l, int h, vector<int>&arr){
    if(l>=h)return ;
    int m = (l+h)/2;
    merge_sort(l,m,arr);
    merge_sort(m+1,h,arr);
    merge(l,m,h,arr);
}


int main(){
    int n=8;
    vector<int>arr= {34,2,1,65,4,98,1,5};
    for(auto p : arr)cout<<p<<" ";
    cout<<endl;
    merge_sort(0,arr.size()-1,arr);
    for(auto p : arr)cout<<p<<" ";
}