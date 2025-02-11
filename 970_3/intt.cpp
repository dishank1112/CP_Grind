#include <iostream>
#include <vector>

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

int main()
{
    fast_io();
    vector<int> arr1{2, 1, 5, 3, 2, 7, 1};
    vector<int> arr2{1, 3, 2, 1};

    int n = arr1.size();
    int m = arr2.size();

    int i = 0; 
    int j = 0; 

    while (i < n && j < m){
        while (i < n && arr2[j] != arr1[i]){
            i++;
        }
       
        if (i < n && arr1[i] == arr2[j]){
            j++;
            i++;
        }
    }


    if (j == m)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
