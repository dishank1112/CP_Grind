#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &v, int s, int e){
    int pivot = v[s];
    int count = 0;
    for (int i = s; i <= e; i++)
    {
        if (v[i] <= pivot){
            count++;
        }
    }
    int pivotIndex = s + count;
    swap(v[pivotIndex], v[s]);
    int left = s;
    int right = e;

    while (left < pivotIndex && right > pivotIndex)
    {
        while (v[left] < pivot)
        {
            left++;
        }
        while (v[right] > pivot)
        {
            right--;
        }
        swap(v[left++], v[right--]);
    }
    
}

void quickSort(vector<int> &v, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int p = partition(v, s, e);
    quickSort(v, s, p - 1);
    quickSort(v, p + 1, e);
}

int main()
{

    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)cin>>v[i];
    for (auto p : v)
    {
        cout << p << " ";
    }
    cout << endl;

    quickSort(v, 0, v.size() - 1);
    for (auto p : v)
    {
        cout << p << " ";
    }

    return 0;
}