#include <iostream>
#include <conio.h>
using namespace std;

class Account
{
private:
    double sum;
    const double rate;
public:
    Account(double Rate, double Sum)
    {
        // Ошибка	C2789	
        rate = Rate;    // "Account::rate": требуется инициализация объекта типа класса, 
        // квалифицированного как const
        // Ошибка	C2166
        // левостороннее значение указывает на объект - константу(const)
        sum = Sum;
    }

    double getRate() const
    {
        return rate;
    }

    double getIncome()
    {
        return sum * rate / 100;
    }

    double getIncome() const
    {
        return sum * rate / 100;
    }

    double getSum()
    {
        return sum;
    }

    double setSum() const
    {                       // Ошибка	C3490	
        sum += getIncome(); // "sum" не может быть изменен, 
        // поскольку доступ к нему осуществляется 
        // через константный объект
        return sum;
    }
};

int main()
{
    Account account1(5, 2000);
    const Account account2(8, 5000);

    account1.getRate();
    account2.getRate();     //  все ОК

    account1.getSum();
    // Ошибка	C2662	
    account2.getSum();  // double Account::getSum(void) : 
    // невозможно преобразовать указатель "this" 
    // из "const Account" в "Account &"

    account1.getIncome();
    account2.getIncome();   //  все ОК

    account1.setSum();
    account2.setSum();

    _getch();
    return 0;
}

