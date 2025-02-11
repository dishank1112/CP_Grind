#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <string>

using namespace std;

const int N = 300043;

int t;
int n, m;
int a[N];
long long sum[N];
int cnt1[N];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> t;
    for (int tc = 0; tc < t; ++tc)
    {
        cin >> n >> m;
        memset(sum, 0, sizeof(sum[0]) * (n + 5));
        memset(cnt1, 0, sizeof(cnt1[0]) * (n + 5));
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            sum[i + 1] = sum[i] + a[i];
            cnt1[i + 1] = cnt1[i] + (a[i] == 1);
        }

        for (int i = 0; i < m; ++i)
        {
            int l, r;
            cin >> l >> r;
            --l;
            int cur_cnt1 = cnt1[r] - cnt1[l];
            long long cur_sum = sum[r] - sum[l];

            if ((r - l) + cur_cnt1 <= cur_sum && r - l > 1)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <cmath>
// #include <map>
// #include <unordered_map>
// #include <set>
// #include <string>

// using namespace std;

// #define ll long long
// #define pb push_back
// #define all(v) (v).begin(), (v).end()
// #define pii pair<int, int>
// #define vi vector<int>
// #define vpii vector<pii>
// #define F first
// #define S second
// #define rep(i, a, b) for (int i = a; i < b; i++)
// #define per(i, a, b) for (int i = b - 1; i >= a; i--)

// void fast_io()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
// }

// template <typename T>
// void read(vector<T> &arr)
// {
//     for (auto &x : arr)
//     {
//         cin >> x;
//     }
// }

// void solve()
// {
//     int n, q;
//     cin >> n >> q;
//     vector<int> arr(n);
//     read(arr);
//     vector<int> pre(n + 1);
//     vector<int> cnt_1(n + 1, 0);
//     pre[0] = 0;
//     cnt_1[0] = 0;
//     rep(i, 0, n)
//     {
//         pre[i + 1] = pre[i] + arr[i];
//     }
//     rep(i, 0, n)
//     {
//         if (arr[i] == 1)
//         {
//             cnt_1[i + 1] = cnt_1[i] + 1;
//         }
//     }
//     for (int i = 0; i < q; i++)
//     {
//         int l, r;
//         cin >> l >> r;
//         l--;
//         int curr_sum = pre[r] - pre[l];
//         int curr_ones = cnt_1[r] - cnt_1[l];
//         if ((r - l) + curr_ones <= curr_sum && r - l > 1)
//         {
//             cout << "YES" << endl;
//         }
//         else
//             cout << "NO" << endl;
//     }
//     return;
// }

// int main()
// {
//     fast_io();

//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }