#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int X, Y, Z;
        cin >> X >> Y >> Z;

        int anuj_goals = 0;
        int pankaj_goals = 0;
        int current_z = Z;

        while (current_z > 1)
        {
            if (X % current_z == 0){
                anuj_goals++;
                X--;
            }
            if(Y % current_z == 0){
                pankaj_goals++;
                Y--;
            }
// well Hello there I am Jiraya U can send Love letters later its really nice to Meet Ya            
            current_z--;
        }
        cout << anuj_goals << " " << pankaj_goals << endl;
    }
    return 0;
}