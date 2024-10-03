#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class RPS
{
    public:

    string a;

};

void cpu (const string& playerchoice)
{
    RPS rps;
    rps.a = playerchoice;

    int random = rand() % 3 ;
    string cpuchoice;

    if (random == 0)
        {
            cpuchoice = "Rock";
        }
        else if (random == 1)
        {
            cpuchoice = "Paper";
        }
        else
        {
            cpuchoice = "Scissors";
        }
    if (cpuchoice == "Rock")
    {
        cout << cpuchoice <<" vs " << rps.a << endl;

        if ( rps.a == "Rock")
        {
            cout << "Tie" << endl;
        }
        else if (rps.a == "Paper")
        {
            cout << "You win" << endl;
        }
        else if (rps.a == "Scissors")
        {
            cout << "You lose" << endl;
        }
        else
        {
            cout << "Error" << endl;
        }
    }
    else if (cpuchoice == "Paper")
    {
        cout << "Paper vs " << rps.a << endl;

        if ( rps.a == "Rock")
        {
            cout << "Lose" << endl;
        }
        else if (rps.a == "Paper")
        {
            cout << "Tie" << endl;
        }
        else if (rps.a == "Scissors")
        {
            cout << "Win" << endl;
        }
        else
        {
            cout << "Error" << endl;
        }
    }
    else if (cpuchoice == "Scissors")
    {
        cout << "Scissors vs " << rps.a << endl;

        if ( rps.a == "Rock")
        {
            cout << "Win" << endl;
        }
        else if (rps.a == "Paper")
        {
            cout << "Lose" << endl;
        }
        else if (rps.a == "Scissors")
        {
            cout << "Tie" << endl;
        }
        else
        {
            cout << "Error" << endl;
        }
    }
    else 
    {
        cout << "Error" << endl;
    }
}

int main()
{
    srand(time(0));

    RPS rps;

    int choice;

    cout << "1. Rock, 2. Paper, 3. Scissors" << endl;
    cin >> rps.a;
    
    if (rps.a != "Rock" && rps.a != "Paper" && rps.a != "Scissors")
    {
        cout << "Invalid choice. Please enter Rock, Paper, or Scissors." << endl;
        return 1;
    }
    cpu(rps.a);
    return 0;
}