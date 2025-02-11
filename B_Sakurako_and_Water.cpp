#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define ll long long
using namespace std;

int main()
{
    ll t;
    cin >> t; 

    while (t--){
        int n;
        cin >> n; 

        vector<vector<int>> arr(n, vector<int>(n));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> arr[i][j];
            }
        }

        int op = 0;

        for (int start = 0; start < n; ++start){
            int i = start, j = 0;
            int min_val = INT_MAX;

            while (i < n && j < n){
                min_val = min(min_val, arr[i][j]);
                ++i;
                ++j;
            }

            if (min_val < 0)
            {
                op += -min_val;
            }
        }

        for (int start = 1; start < n; ++start)
        {
            int i = 0, j = start;
            int min_val = INT_MAX;

            while (i < n && j < n){
                min_val = min(min_val, arr[i][j]);
                ++i;
                ++j;
            }

            if (min_val < 0)
            {
                op += -min_val;
            }
        }

        cout << op << endl;
    }

    return 0;
}
