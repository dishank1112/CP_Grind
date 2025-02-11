#include <iostream>
#include <vector>

using namespace std;

void rearrangeArray(vector<int> &arr)
{
    int n = arr.size();
    int i = 0, j = n - 1;

    while (i < j){
        swap(arr[i], arr[j]);
        i += 2; 
        j--;  
    }

    if (n % 2 == 0)
    {
        std::reverse(arr.begin(), arr.end());
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};

    rearrangeArray(arr);

    for (int i : arr)
    {
        cout << i << " ";
    }

    return 0;
}
