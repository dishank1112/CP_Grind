#include <iostream>
#include <vector>
#include <deque>
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
#define per(i, a, b) for (int i = b - 1; i3 >= a; i--)

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

template <typename T>
void read(vector<T> &arr)
{
    for (auto &x : arr)
    {
        cin >> x;
    }
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    m--; // Convert to 0-based index
    vector<int> arr(n);
    read(arr);

    // Determine the size of the window after removing up to k people
    int L = max(1, n - k);

    // Determine the range of valid windows that include the candidate's position
    int s_start = max(0, m - (L - 1));
    int s_end = min(m, n - L);

    // Use a deque to find the minimum in each window
    deque<int> dq;
    vector<int> minima;

    for (int i = 0; i < n; i++)
        `
        {
            // Remove elements from the back of the deque that are greater than the current element
            while (!dq.empty() && arr[i] <= arr[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);

            // Remove elements from the front of the deque that are out of the current window
            while (!dq.empty() && dq.front() <= i - L)
            {
                dq.pop_front();
            }

            // If the window is of size L, record the minimum
            if (i >= L - 1)
            {
                minima.push_back(arr[dq.front()]);
            }
        }

    // Find the minimum element in all valid windows that include the candidate's position
    int ans = arr[m]; // Initialize with the candidate's own value
    for (int s = s_start; s <= s_end; s++)
    {
        ans = min(ans, minima[s]);
    }

    cout << ans << '\n';
}

int main()
{
    fast_io();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}