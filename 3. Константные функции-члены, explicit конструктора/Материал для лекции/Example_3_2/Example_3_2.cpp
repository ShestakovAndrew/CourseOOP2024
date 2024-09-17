#include <iostream>
#include <stdio.h>
class Date
{
private:
    const int baseYear;
    int& currentYear;
    int day;
    int month;
    int year;
public:
    Date(int currYear) : baseYear{ 2000 }, currentYear(currYear)
    {}
    void setDay(int value)
    {
        day = value;
    }

    int getDay() const
    {
        //return day++;     ошибка при компиляции
        return day;
    }
};

int main()
{
    Date aDate(2020);
    aDate.setDay(10);
    std::cout << aDate.getDay() << std::endl;

    getchar();
    return 0;
}
