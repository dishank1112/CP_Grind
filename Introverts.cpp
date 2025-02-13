#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <queue>
#include <stack>
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

ll fun(int L, int R)
{
    return (ll)L * 1000000LL + R;
}

struct IntervalComparator
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
    {
        int vla = (a.second - a.first) / 2;
        int vlb = (b.second - b.first) / 2;
        if (vla != vlb)
            return vla > vlb; 
        if (a.first != b.first)
            return a.first < b.first;
        return a.second < b.second;
    }
};

bool f2(vector<int> &posii, set<int> &st, int &i, int &j)
{
    int n = posii.size() - 1; 
    if (n <= 1)
        return true;

    if (posii[1] != 1 && posii[1] != n)return false;

    if (posii[1] == 1){
        if (posii[2] != n)return false;
    }
    else{
        if (posii[2] != 1)return false;
    }

    i = min(posii[1], posii[2]);
    j = max(posii[1], posii[2]);
    st.insert(i);
    st.insert(j);
    return true;
}


void f3(int l, int r,set<pair<int, int>, IntervalComparator> &inters,unordered_map<ll, set<pair<int, int>, IntervalComparator>::iterator> &mp){
    if (r - l <= 1)return;
    pair<int, int> new_inter = {l, r};
    auto it = inters.insert(new_inter).first;
    ll key = fun(l, r);
    mp[key] = it;
}

void remm(int L, int R,set<pair<int, int>, IntervalComparator> &inters,unordered_map<ll, set<pair<int, int>, IntervalComparator>::iterator> &inter_mp)
{
    ll key = fun(L, R);
    if (inter_mp.find(key) != inter_mp.end())
    {
        auto it = inter_mp[key];
        inters.erase(it);
        inter_mp.erase(key);
    }
}


bool f4(int n, vector<int> &posii, set<int> &st,
                              set<pair<int, int>, IntervalComparator> &inters,
                              unordered_map<ll, set<pair<int, int>, IntervalComparator>::iterator> &inter_mp)
{
    for (int i = 3; i <= n; i++)
    {
        int ans = posii[i];

        auto it = st.lower_bound(ans);
        if (it == st.end() || it == st.begin())return false;
        int rightyy = *it;
        auto it2 = it;
        it2--;
        int leftii = *it2;

        int dChosen = min(ans - leftii, rightyy - ans);
        int option = (rightyy - leftii) / 2;
        if (dChosen != option)
            return false;

        int maxii = inters.empty() ? 0 : ((*(inters.begin())).second - (*(inters.begin())).first) / 2;
        if (option != maxii)
            return false;

        int gap = rightyy - leftii;
        vector<int> vecc;
        if (gap % 2 == 0){
            vecc.push_back(leftii + gap / 2);
        }
        else
        {
            vecc.push_back(leftii + gap / 2);
            vecc.push_back(leftii + gap / 2 + 1);
        }
        bool flag = false;
        for (int opt : vecc)
        {
            if (opt == ans)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
            return false;
        remm(leftii, rightyy, inters, inter_mp);
        f3(leftii, ans, inters, inter_mp);
        f3(ans, rightyy, inters, inter_mp);
        st.insert(ans);
    }
    return true;
}

bool f(vector<int> &posii, string &temp)
{
    int n = posii.size() - 1; 
    if (n <= 1)
        return true;

    set<int> st;
    int i, j;
    if (!f2(posii, st, i, j))return false;

    set<pair<int, int>, IntervalComparator> inters;
    unordered_map<ll, set<pair<int, int>, IntervalComparator>::iterator> mp;
// well Hellp
    mp.reserve(4 * n);

    f3(i, j, inters, mp);

    return f4(n, posii, st, inters, mp);
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> posii(n + 1, 0);
    rep(i,1,n+1)cin >> a[i];
    rep(i,1,n+1)posii[a[i]] = i;
    string temp = "";
    bool flag = f(posii,temp);
    if(flag == true){
        cout<<"YES"<<endl;
    }
    else cout <<"NO"<<endl;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)solve();
    return 0;
}
