#include <iostream>
#include <stdio.h>
class Date
{
private:
    int day;
    int month;
    int year;
public:
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
    Date aDate;
    aDate.setDay(10);
    std::cout << aDate.getDay() << std::endl;

    getchar();
    return 0;
}
