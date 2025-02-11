#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <tuple>

using namespace std;


using std::cin, std::cout;
using ll = long long;
using u64 = unsigned long long;
using db = double;
const int N = 1000005;
const int mod = 998244353;
int fac[N], ifac[N], inv[N];
int comb(int n, int m)
{
    if (m < 0 || n < m)
        return 0;
    return (u64)fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
int n;
int a[N];
int main()
{
    std::ios::sync_with_stdio(false), cin.tie(0);
    fac[0] = ifac[0] = fac[1] = ifac[1] = inv[1] = 1;
    for (int i = 2; i < N; ++i)
    {
        inv[i] = u64(mod - mod / i) * inv[mod % i] % mod;
        fac[i] = (u64)fac[i - 1] * i % mod;
        ifac[i] = (u64)ifac[i - 1] * inv[i] % mod;
    }

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    ll ans = 0;
    int gx = n - 1, gy = n - 1;
    for (int lcp = 0, s = 0; lcp < n; ++lcp)
    {
        int x = lcp, y = s;
        if (lcp + 1 == n)
            ans += x == y;
        if (y < x)
            break;
        if (y > n)
            break;
        int lim = std::min(a[lcp + 1] - 1, gy - y);
        for (int i = (x == y); i <= lim; ++i)
        {
            int px = x + 1, py = y + i;
            int n = gx - px, m = gy - py;
            ans += comb(n + m, n);
            ans -= comb(n + m, n + px - py - 1);
        }
        s += a[lcp + 1];
    }
    // well hello there 
    ans %= mod;
    ans += mod;
    ans %= mod;
    cout << ans << '\n';
// well hello 
}
