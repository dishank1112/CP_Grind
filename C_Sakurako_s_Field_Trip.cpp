#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int solve(vector<int> &a)
{
    int n = a.size();
    int disturbance = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        if (a[i] == a[i + 1])
        {
            ++disturbance;
        }
    }

    if (disturbance == 0)
    {
        return 0;
    }

    for (int i = 0; i < n - 1; ++i)
    {
        if (a[i] == a[i + 1]){
            if (i > 0 && a[i - 1] != a[i + 1]){
                return max(1, disturbance - 1);
            }
            if (i < n - 2 && a[i] != a[i + 2]){
                return max(1, disturbance - 1);
            }
        }
    }
    return max(1, disturbance - 1);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        cout << solve(a) << endl;
    }
    return 0;
}
