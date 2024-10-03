#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int blocks;

    cout << "How many blocks ? (choose between 1 and 9)" << endl;
    cin >> blocks;

    char x = '#';

    if(blocks > 0 && blocks < 9)
    {
        for (int i = 0; i < blocks; i++)
        {
            int k = i + 1;
            for (int i = k; i < blocks; i++)
            {
                cout << " ";
            }
            for (int i = k; i > 0; i--)
            {
                cout << x;
            }
            cout << " ";
            for (int i = k; i > 0; i--)
            {
                cout << x;
            }
            cout << endl;
        }
    }
    else 
    {
        cout << "Invalid input" << endl;
    }
}