#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k, a, b;
    cin >> n >> k >> a >> b;

    ll cost = 0;

    // Special case: if k == 1, then division never helps.
    if (k == 1)
    {
        cout << a * (n - 1) << "\n";
        return 0;
    }

    while (n > 1)
    {
        // If n is divisible by k, decide whether to divide or subtract.
        if (n % k == 0)
        {
            ll new_n = n / k;
            // Cost to subtract until new_n is reached:
            ll subtractCost = a * (n - new_n);
            // If subtracting is cheaper than performing the division,
            // subtract until new_n, otherwise perform the division.
            if (subtractCost < b)
            {
                cost += subtractCost;
            }
            else
            {
                cost += b;
            }
            n = new_n;
        }
        // If n is not divisible by k, subtract the remainder to reach the next number divisible by k.
        else
        {
            ll remainder = n % k; // how far n is above a multiple of k.
            // We can't subtract more than (n - 1) (we want to stop at 1).
            ll toSubtract = remainder;
            if (n - toSubtract < 1)
                toSubtract = n - 1;
            cost += a * toSubtract;
            n -= toSubtract;
        }
    }

    cout << cost << "\n";
    return 0;
}
