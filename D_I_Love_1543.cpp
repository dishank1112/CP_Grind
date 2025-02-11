#include <iostream>
#include <vector>
#include <string>

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



template <typename T>
void read(vector<T> &arr)
{
    for (auto &x : arr)
    {
        cin >> x;
    }
}
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int f(string &str, const string &t)
{
    int cnt = 0;
    string s = str + str.substr(0, t.size() - 1);
    for (int i = 0; i <= s.size() - t.size(); ++i)
    {
        if (s.substr(i, t.size()) == t)
        {
            cnt++;
        }
    }
    return cnt;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<string> arr(n); 
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<string> layers;
    int insider_r = 0;
    int insider_c = n - 1;
    int outside_r = 0;
    int outside_c = m - 1;

    while (insider_r <= insider_c && outside_r <= outside_c)
    {
        string str;


        for (int i = outside_r; i <= outside_c; ++i)
        {
            str += arr[insider_r][i];
        }

        for (int i = insider_r + 1; i <= insider_c; ++i)
        {
            str += arr[i][outside_c];
        }

        if (insider_r < insider_c)
        {
            for (int i = outside_c - 1; i >= outside_r; --i)
            {
                str += arr[insider_c][i];
            }
        }

        if (outside_r < outside_c)
        {
            for (int i = insider_c - 1; i > insider_r; --i)
            {
                str += arr[i][outside_r];
            }
        }

        layers.push_back(str);
        insider_r++;
        insider_c--;
        outside_r++;
        outside_c--;
    }

    string target = "1543";
    int total = 0;

    for (auto &it : layers){
        total += f(it, target);
    }

    cout << total << endl;
}

int main()
{
    fast_io();

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}

