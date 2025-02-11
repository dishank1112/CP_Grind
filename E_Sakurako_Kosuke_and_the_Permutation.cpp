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



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> vecc(n);

        for (auto &p : vecc)cin >> p;

        vector<bool> vis(n + 1, false);

        long long ans = 0;

        for (int i = 1; i <= n; i++)
            if (!vis[i]){
                int cntt = 0;
                int ind = i;
                while (!vis[ind]){
                    vis[ind] = true;
                    ind = vecc[ind - 1];
                    cntt++;
                }
                if (cntt >= 3)ans += (cntt - 1)/2;
            }
        cout << ans <<endl;
    }
}
