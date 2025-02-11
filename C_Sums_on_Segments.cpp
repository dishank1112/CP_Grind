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
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int special = -1;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] != 1 && arr[i] != -1)
            special = i;
    }
// well Hello there I am jiraya u cAN SEND LOVE KLTTERS LATER
// WELL hello there I am 
    vector<int> left(n, 0);  
    vector<int> right(n, 0); 

    if (special != -1)
    {
        // Process the left side
        if (special > 0)
        {
            left[0] = arr[0];
            for (int i = 1; i <= special - 1; i++)
            {
                if (arr[i] == -1 && arr[i - 1] == -1)
                {
                    left[i] = left[i - 1] - 1;
                }
                else if (arr[i] == -1 && arr[i - 1] != -1)
                {
                    left[i] = -1;
                }
                else if (arr[i] == 1 && arr[i - 1] == 1)
                {
                    left[i] = left[i - 1] + 1;
                }
                else
                {
                    left[i] = 1;
                }
            }
        }

        // Process the right side
        if (special < n - 1)
        {
            right[special] = arr[special];
            for (int i = special + 1; i <= n - 1; i++)
            {
                if (arr[i] == -1 && arr[i - 1] == -1)
                {
                    right[i] = right[i - 1] - 1;
                }
                else if (arr[i] == -1 && arr[i - 1] != -1)
                {
                    right[i] = -1;
                }
                else if (arr[i] == 1 && arr[i - 1] == 1)
                {
                    right[i] = right[i - 1] + 1;
                }
                else
                {
                    right[i] = 1;
                }
            }
        }

        // Print the results
        for (int i = 0; i < special; i++)
            cout << left[i] << " ";
        cout << "\n";
        for (int i = special; i < n; i++)
            cout << right[i] << " ";
        cout << endl;
    }
}
int f(int ind,vector<int>&arr){
    if(ind >= arr.size())return 0;
    int ans  = 0;
    for(int i=i;i<arr.size();i++){
        ans = i + f(i+1,arr);
    }
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