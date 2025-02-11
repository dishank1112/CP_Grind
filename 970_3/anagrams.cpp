#include <iostream>
#include <vector>
#include <unordered_map>

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

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool areEqual(unordered_map<char, int> &mp1, unordered_map<char, int> &mp2){
    for (auto &p : mp2){
        if (mp1[p.first] != p.second){
            return false;
        }
    }
    return true;
}

int main()
{
    fast_io();

    string s = "abac";
    string t = "ccabcaaacbcaa";
    int k = s.size();
    int n = t.size();

    unordered_map<char, int> mp1;
    
    unordered_map<char, int> mp2;

    rep(i, 0, k) mp2[s[i]]++;

    int ans = 0;

    rep(i, 0, k) mp1[t[i]]++;

    
    if (areEqual(mp1, mp2))
        ans++;

    for (int i = k; i < n; i++)
    {
       
        mp1[t[i - k]]--;
        if (mp1[t[i - k]] == 0){
            mp1.erase(t[i - k]); 
        }
        mp1[t[i]]++;
        if (areEqual(mp1, mp2))
            ans++;
    }

    cout <<ans<<endl;

    return 0;
}
