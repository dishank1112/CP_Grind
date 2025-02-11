// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <cmath>

// using namespace std;

// #define ll long long
// #define pb push_back
// #define all(v) (v).begin(), (v).end()
// #define pii pair<int, int>
// #define vi vector<int>
// #define vpii vector<pii>
// #define F first
// #define S second
// #define rep(i, a, b) for (int i = a; i < b; i++)
// #define per(i, a, b) for (int i = b - 1; i >= a; i--)

// void fast_io()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
// }

// int main()
// {
//     fast_io();

//     // #ifndef ONLINE_JUDGE
//     //     freopen("./input.txt", "r", stdin);
//     //     freopen("./output.txt", "w", stdout);
//     // #endif

//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         ll n, k;
//         cin >> n >> k;
//         vector<ll> arr(n);
//         rep(i, 0, n) cin >> arr[i];
//         sort(arr.begin(), arr.end());
//         ll ans = 0;

//         for(ll i=0;i<n;i++)
//         {
            
//             if (k <= (n - i) * arr[i])
//             {
//                 ans += k;
//                 break;
//             }
//             else
//             {
//                 ans += arr[i] + 1;
//                 k -= arr[i];
//             }
//         }
//         cout << ans << endl;
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// const int MOD = 1e9 + 7;
// #define ll long long

// // Comparator function for sorting based on the first element of the pair
// bool comp(const array<ll, 3> &a, const array<ll, 3> &b)
// {
//         return a[0] < b[0];
// }

// int main()
// {
//         ll testCases;
//         cin >> testCases;

//         while (testCases--)
//     {
//                 ll numPairs;
//                 cin >> numPairs;

//                 // Define vector for pairs and values
//         vector<array<ll, 2>> pairs(numPairs);
//                 vector<ll> values(2 * numPairs);

//                 // Input pairs and store values
//         for (ll i = 0; i < numPairs; ++i)
//         {
//                         cin >> pairs[i][0] >> pairs[i][1];
//                         values[2 * i] = pairs[i][0];
//                         values[2 * i + 1] = pairs[i][1];
//                    
//         }

//                 // Sort the values array
//         sort(values.begin(), values.end());
//                 map<ll, ll> valueMap;

//                 // Map unique values to indices
//         ll index = 1;
//                 for (ll i = 0; i < 2 * numPairs; i++)
//         {
//                         if (valueMap.find(values[i]) == valueMap.end())
//             {
//                                 valueMap[values[i]] = index++;
//                            
//             }
//                    
//         }

//                 // Compress the pairs
//         vector<array<ll, 2>> compressed(numPairs);
//                 for (ll i = 0; i < numPairs; ++i)
//         {
//                         compressed[i][0] = valueMap[pairs[i][0]];
//                         compressed[i][1] = valueMap[pairs[i][1]];
//                    
//         }

//                 // Prepare the result array
//         vector<array<ll, 3>> result(numPairs);
//                 for (ll i = 0; i < numPairs; ++i)
//         {
//                         ll sum = compressed[i][0] + compressed[i][1];
//                         result[i] = {sum, pairs[i][0], pairs[i][1]};
//                    
//         }

//                 // Sort the result array based on the first column
//         sort(result.begin(), result.end(), comp);

//                 // Output the results
//         for (ll i = 0; i < numPairs; ++i)
//         {
//                         cout << result[i][1] << " " << result[i][2] << " ";
//                    
//         }
//                 cout << endl;
//            
//     }

//         return 0;
// }


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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

int main() {
    fast_io();

    #ifndef ONLINE_JUDGE
        freopen("./input.txt", "r", stdin);
        freopen("./output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        // Add your problem-solving logic here
    }

    return 0;
}