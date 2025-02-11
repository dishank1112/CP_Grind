#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, health;
        cin >> n >> health;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int best = a[n - 1];
        int second_best = a[n - 2];
        if (health % (best + second_best) == 0){
            cout << 2 * (health / (best + second_best));
        }

        else if (health % (best + second_best) <= best){
            cout << 2 * (health / (best + second_best)) + 1;
        }
        else{
            cout << 2 * (health / (best + second_best)) + 2;
        }
        cout << '\n';
    }
    return 0;
}