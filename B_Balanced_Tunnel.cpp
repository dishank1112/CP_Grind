#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main()
{
    fast_io();

    int n;
    cin >> n;
    vector<int> enterr(n);
    vector<int> exitt(n);

    rep(i, 0, n) cin >> enterr[i];
    rep(i, 0, n) cin >> exitt[i];
    if(n == 1){
        cout<<0<<endl;
    }
    else if(n == 2){
        if(enterr[0] ==   exitt[0]){
            cout<<0<<endl;
        }
        else cout<<1<<endl;
     }
     else{
    unordered_map<int, int> exit_pos;
    rep(i, 0, n)
    {
        exit_pos[exitt[i]] = i;
    }

    int max_exit_pos = -1;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int car = enterr[i];
        int pos = exit_pos[car];

        if (pos < max_exit_pos)
        {
            ans++;
        }
        else
        {
  
            max_exit_pos = pos;
        }
    }

    cout << ans << endl;
    }
    return 0;
}
