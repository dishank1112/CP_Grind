#include <iostream>
#include <vector>
#include <unordered_map>

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

    using namespace std;

int main()
{
    ll t;
    cin >> t; 

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        rep(i,0,n)
        {
            cin >> a[i];
        }

        unordered_map<long long, int> mp; 
        mp[0] = -1;                       

        long long pre_sum = 0;
        int valid_ind = -1;
        int ans = 0;

        rep(i,0,n)
        {
            pre_sum += a[i];

    
            if (mp.find(pre_sum) != mp.end()){
                int oc_last = mp[pre_sum];

                if (oc_last >= valid_ind)
                {
                    ans++;   
                    valid_ind = i; 
                }
            }
            mp[pre_sum] = i;
        }
        cout<<ans<<endl;
    }

    return 0;
}
