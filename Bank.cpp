#include <iostream>
#include <string>

using namespace std;

class bankaccount
{
    private:
    string number;
    string name;
    string type;
    float balance;

    public:
    bankaccount(string acc, string name, string type, float bal)
    {
        number = acc;
        name = name;
        type = type;
        balance = bal;
    }

    void setacc(string acc)
    {
        number = acc;
    }
    void setname(string name)
    {
        name = name;
    }
    void settype(string type)
    {
        type = type;
    }
    void setbalance( float bal )
    {
        balance = bal;
    }
    string getacc()
    {
        return number;
    }
    string getname()
    {
        return name;
    }
    string gettype()
    {
        return type;
    }
    float getbal()
    {
        return balance;
    }

    void deposit(float amount)
    {
        balance += amount;
    }
    void withdraw(float amount)
    {
        if(amount > balance)
        {
            cout << "Insufficient balance." << endl;
        }
        else
        {
            balance -= amount;
        }
    }
    bankaccount operator+(const bankaccount& other)
    {
        bankaccount result("","","",0);
        result.balance = balance + other.balance;
        return result;
    }
    bool operator==(const bankaccount& other)
    {
        return number == other.number;
    }
    virtual float interest()
    {
        return 0.0;
    }
};

class savings : public bankaccount
{
    public:
    savings(string acc, string name, float bal) : bankaccount(acc, name, "savings", bal) {}
    float interest() override
    {
        return 0.01;
    }
};

class checking : public bankaccount
{
    public:
    checking(string acc, string name, float bal) : bankaccount( acc,  name, "checking", bal){}
    float interest() override
    {
        return 0.0;
    }
};


int main()
{
    bankaccount acc1("123456", "Alex Brenton", "savings", 1000.0);
    savings acc2("789012", "Jane Smith", 2000.0);
    checking acc3("345678", "Bob Johnson", 5000.0);

    acc1.deposit(500.0);
    acc2.withdraw(2000.0);
    acc3.withdraw(2500.0);

    bankaccount acc4 = acc1 + acc2;
    cout << "Combined balance: " << acc4.getbal() << endl;

    if(acc1==acc2)
    {
        cout << "Matched" << endl;
    }
    else 
    {
        cout << "Did not match" << endl;
    }

    cout << "Savings" << acc2.interest() << endl;
    cout << "Checking" << acc3.interest() << endl;

    return 0 ;
}