#include <iostream>
#include <vector>
using namespace std;

int f(int s, int e, int target, vector<int> &arr)
{
    if (s > e)return -1;           
    int m = s + (e - s) / 2; 
    if (arr[m] == target)
        return m + 1; 
    if (arr[m] > target)
    {
        return f(s, m - 1, target, arr); 
    }
    else
    {
        return f(m + 1, e, target, arr); 
    }
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << f(0, arr.size() - 1, 11, arr) << endl;
    return 0;
}
