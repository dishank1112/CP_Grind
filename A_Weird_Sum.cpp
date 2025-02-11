#include <iostream>
#include <queue>
#include <algorithm>
#include <iterator>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cmath>
#include <bitset>
#include <cstring>
#include <iomanip>
#include <list>
/// well Hello there I am 
using namespace std;
#define int long long
// #define endl "\n"
#define double long double
// #define INT_MIN -1000000000000000
// #define INT_MAX 1e18
long long power(int N, int R){
    if (R == 0)return 1;

    if (R == 1)return (N % 998244353);

    long long ans = 1;
    long long know = power(N, R / 2) % 998244353;
    if (R % 2)ans = (ans * N) % 998244353;
    return (ans * ((know * know) % 998244353)) % 998244353;
}

bool comp(pair<int, int> &p1, pair<int, int> &p2)
{
    return p1.second < p2.second;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        map<int, vector<pair<int, int>>> mp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int x;
                cin >> x;
                mp[x].push_back({i, j});
            }
        }
        int ans = 0;
        for (auto it : mp)
        {
            vector<pair<int, int>> v = it.second;
            sort(v.begin(), v.end());
            int sum = 0;
            for (int i = 0; i < v.size(); i++)
                sum += v[i].first;
            for (int i = 0; i < v.size(); i++)
            {
                sum -= v[i].first;
                ans += (sum - ((v.size() - 1 - i) * v[i].first));
            }
            sort(v.begin(), v.end(), comp);
            sum = 0;
            for (int i = 0; i < v.size(); i++)
                sum += v[i].second;
            for (int i = 0; i < v.size(); i++)
            {
                sum -= v[i].second;
                ans += (sum - ((v.size() - 1 - i) * v[i].second));
            }
        }
        cout << ans << endl;
    }
    return 0;
}