#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int i, j, k;
    int len = s.length();
    bool val = false;
    // string str;
    int num;

    // check for 8
    for (int i = 0; i < len; ++i)
    {
        if (s[i] == '8' || s[i] == '0')
        {
            val = true;
            num = s[i] - '0';
            break;
        }
    }
    if (val)
        cout << "YES\n"<< num;
    else
    {
        for (int i = 0; i < len; ++i)
        {
            for (int j = i + 1; j < len; ++j)
            {
                if (s[i] != '0')
                {
                    num = (s[i] - '0') * 10 + (s[j] - '0');
                    if (num % 8 == 0)
                    {
                        val = true;
                        break;
                    }
                }
            }
            if (val)
                break;
        }
        if (val)
            cout << "YES\n"
                 << num;
        else
        {
            for (int i = 0; i < len; ++i)
            {
                for (int j = i + 1; j < len; ++j)
                {
                    for (int k = j + 1; k < len; ++k)
                    {
                        if (s[i] != '0')
                        {
                            num = (s[i] - '0') * 100 + (s[j] - '0') * 10 + (s[k] - '0');
                            if (num % 8 == 0)
                            {
                                val = true;
                                break;
                            }
                        }
                    }
                    if (val)
                        break;
                }
                if (val)
                    break;
            }
            if (val)
                cout << "YES\n"
                     << num;
            else
                cout << "NO\n";
        }
    }

    return 0;
}