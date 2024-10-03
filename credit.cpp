#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
string vectorString( vector <int> vec)
{
    ostringstream oss;
    for(size_t i = 0; i < vec.size(); i++)
    {
        oss << vec[i];
    }
    return oss.str();
}

int main ()
{
    string card_num, result;
    int evennum = 0;
    int sum = 0;
    int oddnum = 0;
    int evensum = 0;
    vector<int> cardeven, cardodd, cardresult;

    cout << "Enter your credit card number: " << endl;
    cin >> card_num;

    if(card_num.length() > 0 && card_num.length() <= 21)
    {
        for(size_t i = 0; i < card_num.length(); i++)
        {
            int cardnum = card_num[i] - '0';

            if(i % 2 != 0)
            {
                cardeven.push_back(cardnum);
                evennum += cardnum;
            }
            else 
            {
                cardodd.push_back(cardnum*2);
                oddnum += cardnum;
            }
        }
        result = vectorString(cardodd);

        if(result.length() > 0 && result.length() <= 21)
        {
            for(size_t i = 0; i < result.length(); i++)
            {
                sum += result[i] - '0';
            }
        }
        for (size_t i = 0; i < cardeven.size(); i++)
        {
            evensum += cardeven[i];
        }
        int total = evensum + sum;
        if(total % 10 == 0)
        {
            if(card_num.size() == 15)
            {
                cout << "American Express" << endl;
            }
            else if(card_num.size() == 13 || (card_num.size() == 16 && card_num[1] == '4'))
            {
                cout << "VISA" << endl;
            }
            else if(card_num.size() == 16 && (card_num.substr(0, 2) >= "51" && card_num.substr(0, 2) <= "55"))
            {
                cout << "Mastercard" << endl;
            }
        }
        else
        {
            cout << "Invalid card number" << endl;
        }
    }
    return 0;
}
