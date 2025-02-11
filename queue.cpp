#include <iostream>
#include <vector>
#include<queue>
using namespace std;

#define ll long long
#define pb push_back
#define all(v) (v).begin(), (v).end()

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main()
{
    fast_io();

    // vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    // int i = 0; 

    // while (arr.size() > 1)
    // {
        
    //     i = (i + 1) % arr.size();

    //     arr.erase(arr.begin() + i);

    //     if (i == arr.size())
    //     {
    //         i = 0; 
    //     }
    // }

    // cout << "Last remaining element: " << arr[0] << endl;
    // int n = 11;
    // queue<int>q;
    // for(int i=1;i<=n;i++){
    //     q.push(i);
    // }

    // while(q.size()>1){
    //     int val = q.front();
    //     q.pop();
    //     int val2 = q.front();
    //     q.pop();
    //     cout<<val2<<" "<<endl;
    //     q.push(val);
    // }
    // cout<<"Remaining : "<<q.front()<<endl;


        deque<int> q; // Use deque instead of queue
        q.push_back(1);
        q.push_back(8);
        q.push_back(7);
        q.push_back(5);
        q.push_back(3);

        // Store the front and back indices for swapping
        int i = 0;            // Front index
        int j = q.size() - 1; // Back index

        // Swap elements from front to back until indices meet
        while (i < j)
        {
            swap(q[i], q[j]); // Swap elements
            i++;              // Move front index forward
            j--;              // Move back index backward
        }

        // Print the updated deque
        for (auto it : q)
        {
            cout << it << " "; // Print each element
        }
        cout << endl;

        return 0;
    }
