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
typedef unsigned long long ull;
const ull BASE = 131ULL; 
vector<ull> powArr;
void initPowArr(int n)
{
    powArr.resize(n + 1);
    powArr[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        powArr[i] = powArr[i - 1] * BASE;
    }
}

int booth(const vector<int> &s)
{
    int n = s.size();
    int i = 0, j = 1, k = 0;
    while (i < n && j < n && k < n)
    {
        if (s[(i + k) % n] == s[(j + k) % n])
        {
            k++;
            continue;
        }
        if (s[(i + k) % n] > s[(j + k) % n])
            i = i + k + 1;
        else
            j = j + k + 1;
        if (i == j)
            j++;
        k = 0;
    }
    return min(i, j);
}

struct DPState
{
   
    ull hash;
    int len;
    int first;
    int decision;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int N, M;
        cin >> N >> M;
        vector<int> A(N), B(M);
        for (int i = 0; i < N; i++)
            cin >> A[i];
        for (int j = 0; j < M; j++)
            cin >> B[j];

        int start = booth(B);
        vector<int> bestB(M);
        for (int i = 0; i < M; i++)
        {
            bestB[i] = B[(start + i) % M];
        }

        vector<ull> bestB_prefix(M + 1, 0);
        for (int i = 0; i < M; i++)
        {
            bestB_prefix[i + 1] = bestB_prefix[i] * BASE + (ull)(bestB[i] + 7);
        }
        ull bestB_hash = bestB_prefix[M];

        initPowArr(N + 10);

        vector<DPState> dp(N + 1);
        dp[N] = {0, 0, 0, -1}; 
        for (int i = N - 1; i >= 0; i--)
        {
            
            ull hash1 = ((ull)(A[i] + 7) * powArr[dp[i + 1].len] + dp[i + 1].hash);
            DPState opt1 = {hash1, dp[i + 1].len + 1, A[i], 0};

            DPState opt2;
            if (i <= N - M)
            {
     
                ull hash2 = bestB_hash * powArr[dp[i + M].len] + dp[i + M].hash;
                opt2 = {hash2, dp[i + M].len + M, bestB[0], 1};
            }
            else
            {
                opt2 = {ULLONG_MAX, N - i, INT_MAX, -1};
            }
            bool takeOption2 = false;
            {
                vector<int> S1, S2;
                S1.push_back(A[i]);
           
                if (i <= N - M)
                {
                    if (A[i] > bestB[0])
                        takeOption2 = true;
                    else
                        takeOption2 = false;
                }
            }

            if (takeOption2)
            {
                dp[i] = opt2;
            }
            else
            {
                dp[i] = opt1;
            }
        }


        int i = 0;
        vector<int> result;
        while (i < N)
        {
            if (i <= N - M && dp[i].decision == 1)
            {
                for (int j = 0; j < M; j++)
                {
                    result.push_back(bestB[j]);
                }
                i += M;
            }
            else
            {
                result.push_back(A[i]);
                i++;
            }
        }
        for (int x : result)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
