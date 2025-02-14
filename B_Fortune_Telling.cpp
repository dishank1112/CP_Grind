#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        ll x, y;
        cin >> n >> x >> y;

        ll sum_parity = 0; 
        for (ll i = 0; i < n; i++){
            ll ai;
            cin >> ai;
            sum_parity = (sum_parity + (ai & 1))%2;
        }

        ll alice_parity = ((x & 1) + sum_parity)%2;
        ll y_parity = y & 1;

        if (alice_parity == y_parity)
            cout << "Alice" << "\n";
        else
            cout << "Bob" << "\n";
    }

    return 0;
}
