#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
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
    string str;
    cin >> str;

    int countn = 0, counts = 0, counte = 0, countw = 0;

    // Count occurrences of each direction
    for (char ch : str)
    {
        if (ch == 'N')
            countn++;
        else if (ch == 'S')
            counts++;
        else if (ch == 'E')
            counte++;
        else if (ch == 'W')
            countw++;
    }

    // Check if counts of opposing directions are even
    if ((countn + counts) % 2 != 0 || (counte + countw) % 2 != 0)
    {
        cout << "NO\n";
        return;
    }

    string ans;
    int halfn = countn / 2;
    int halfs = counts / 2;
    int halfe = counte / 2;
    int halfw = countw / 2;

    int i_n = 0, i_s = 0, i_e = 0, i_w = 0;

    // Build the ans string based on conditions
    for (char ch : str)
    {
        if (ch == 'N')
        {
            if (i_n < halfn)
                ans += 'H';
            else
                ans += 'R';
            i_n++;
        }
        else if (ch == 'S')
        {
            if (i_s < halfs)
                ans += 'H';
            else
                ans += 'R';
            i_s++;
        }
        else if (ch == 'E')
        {
            if (i_e < halfe)
                ans += 'H';
            else
                ans += 'R';
            i_e++;
        }
        else if (ch == 'W')
        {
            if (i_w < halfw)
                ans += 'H';
            else
                ans += 'R';
            i_w++;
        }
    }

    cout << ans << "\n";
    cout << "YES\n";
}

int main() {
    fast_io();
        solve();
    

    return 0;
}