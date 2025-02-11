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


void read(string &str)
{
    cin>>str;
}

void solve() {
    string str;
    read(str);

    int q;
    cin>>q;
    
    set<int> stt;
     int n = str.size();

    for (int i = 0; i <= n - 4; i++){
        if (str.substr(i, 4) == "1100") stt.insert(i);
    }

    while (q--){
        int posi;        
        cin >> posi;
        posi--;
        char val;
        cin>>val;

        int start = max(0, posi - 3);
        int end = min(n - 4, posi);

        rep(ind,start,end+1){
            if (str.substr(ind, 4) == "1100"){
                stt.erase(ind);
            }
        }

        str[posi] = val;

        rep(i,start,end+1){
            if (str.substr(i, 4) == "1100"){
                stt.insert(i);
            }
        }

        if (stt.empty())cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return ;
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




















// void queries()
// {
//     int testcase;
//     cin >> testcase;

//     while (testcase--)
//     {
//         string s;
//         cin >> s;
//         int n = s.length();
//         int query;
//         cin >> query;

//         set<int> substring;

//         for (int i = 0; i <= n - 4; i++)
//         {
//             if (s.substr(i, 4) == "1100")
//             {
//                 substring.insert(i);
//             }
//         }


//     }
// }

// int main()
// {
//     queries();
//     return 0;
// }