#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t; 

    while (t--)
    {
        int n;
        cin >> n; 

        int maxWidth = 0, maxHeight = 0;
        for (int i = 0; i < n; ++i)
        {
            int w, h;
            cin >> w >> h;
        
            maxWidth = max(maxWidth, w);
            maxHeight = max(maxHeight, h);
        }

    
        int minPerimeter = 2 * (maxWidth + maxHeight);
        cout << minPerimeter << endl;
    }

    return 0;
}
