#include <iostream>
#include <conio.h>
using namespace std;

class Account
{
private:
    double sum;
    const double rate;
public:
    Account(double Rate, double Sum) : rate{ Rate }
    {
        this->sum = Sum;
    }

    double getRate() const
    {
        return rate;
    }

    double getIncome()          // перегрузка: неконстантный метод
    {
        return sum * rate / 100;
    }

    double getIncome() const    // перегрузка: такой же, но константный метод
    {
        return sum * rate / 100;
    }

    double getSum() const
    {
        return sum;
    }

    double setSum()
    {
        sum += getIncome();
        return sum;
    }
};

int main()
{
    Account account1(5, 2000);
    const Account account2(8, 5000);    // константный объект

    account1.getRate();
    account2.getRate();

    account1.getSum();
    account2.getSum();

    account1.getIncome();   // вызывается неконстантный метод double getIncome()
    account2.getIncome();   // вызывается константный метод double getIncome() const

    account1.setSum();

    _getch();
    return 0;
}

