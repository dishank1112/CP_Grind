#include <iostream>
#include <vector>
#include <algorithm>

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

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int f(vector<char> &arr)
{
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 'L')
        {
            ans += i;
        }
        else
        {
            ans += arr.size() - i;
        }
    }
    return ans;
}

int main()
{
    fast_io();
    ll t;
    cin >> t;
    while (t--)
    {
        vector<char> arr{'R', 'R', 'L', 'R', 'L'};

        int i = 0, j = arr.size() - 1;
        int maxi = f(arr);

        while (i < j)
        {

            if (arr[i] == 'R')
            {
                i++;
            }

            else if (arr[j] == 'L')
            {
                j--;
            }

            else
            {
                swap(arr[i], arr[j]);
                maxi = max(maxi, f(arr));
                i++;
                j--;
            }
        }

        cout << "Maximum value: " << maxi << '\n';
    }

    return 0;
}
