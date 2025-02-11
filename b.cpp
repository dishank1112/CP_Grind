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
// Well Hello There I am Jiraya U can send love letters later its really nice to meet you
int f(int N, const string &sequence)
{
    int currentPlayer = 1; // Start with player 1
    int direction = 1;     // 1 for clockwise, -1 for anti-clockwise

    for (char card : sequence)
    {
        if (card == 'U')
        {
            // Move to the next player in the current direction
            currentPlayer = (currentPlayer + direction + N - 1) % N + 1;
        }
        else if (card == 'S')
        {
// well hello there I am jiraya u can send love letters later its really noice to meet ya

            currentPlayer = (currentPlayer + 2 * direction + N - 1) % N + 1;
        }
        else if (card == 'R')
        {
            // Reverse the direction
            direction = -direction;
            // Move to the next player in the new direction
            currentPlayer = (currentPlayer + direction + N - 1) % N + 1;
        }
    }

    return currentPlayer;
}

    void solve()
    {
        int n;
        cin >> n;
        // Gimme Logic dude...
        int m ;
        cin>>m;
        string str;
        cin >> str;
        int ans = f(n, str);
        cout << ans <<'\n';
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