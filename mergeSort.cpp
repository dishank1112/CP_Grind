#include <iostream>
#include <vector>

using namespace std;

// merge -->
vector<int> merge(int s, int e, vector<int> &arr)
{
    int m = (s + e) / 2;
    int i = s;
    int j = m + 1;
    vector<int> temp;

    while (i <= m && j <= e){
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= m)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= e)
    {
        temp.push_back(arr[j]);
        j++;
    }
    
    for (int i = s; i <= e; i++)
    {
        arr[i] = temp[i - s];
    }
    return arr;
}
// divide -->

void mergeSort(int s, int e, vector<int> &arr)
{
    if (s >= e)
    {
        return;
    }
    int m = (s + e) / 2;

    mergeSort(s, m, arr);
    mergeSort(m + 1, e, arr);
    merge(s, e, arr);
}

int main()
{
    vector<int> arr{70, 10, 20, 50, 40, 30};

    mergeSort(0, arr.size() - 1, arr);

    for (auto p : arr)
        cout << p << " ";

    return 0;
}
