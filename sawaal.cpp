#include <iostream>
#include <vector>
#include <algorithm> 
#include <map>
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

void fast_io(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main()
{
    fast_io();

    string t = "cata";
    string s = "tttaccaccattacc";

    map<char, int> mp1; 
    map<char, int> mp2; 

    for (int i = 0; i < s.size(); i++)
    {
        mp1[s[i]]++; 
    }

    for (int i = 0; i < t.size(); i++){
        mp2[t[i]]++; 
    }

    int mini = 1000; 

    for (auto p : mp2){
        char ch = p.first;             
        int cnt = p.second; 

        if (mp1.find(ch) == mp1.end()) {
            mini = 0;
            break;
        }
        else
        {
            mini = min(mini, mp1[ch] / cnt); 
        }
    }

    cout << "No = " << mini << endl;

    return 0;
}
