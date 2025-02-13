#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void solve()
{
    string str;
    cin >> str;

    int cntu = 0, cntd = 0;
    int firstLower = -1;

    // Find the first lowercase character from left
    for (int i = 0; i < str.size(); i++)
    {
        if (islower(str[i]))
        {
            firstLower = i;
            break;
        }
    }

    if (firstLower == -1)
    {
        // No lowercase letter found, no operations needed
        cout << 0 << endl;
        return;
    }

    // Count uppercase and lowercase letters after first lowercase letter
    for (int i = firstLower; i < str.size(); i++)
    {
        if (isupper(str[i]))
            cntu++;
        else
            cntd++;
    }

    cout << min(cntu, cntd) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
// 
    solve();
    return 0;
}
