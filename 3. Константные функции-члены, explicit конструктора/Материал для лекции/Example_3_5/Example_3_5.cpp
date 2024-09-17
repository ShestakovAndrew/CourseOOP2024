#include <iostream>
#include <stdio.h>

class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date(int day, int month, int year)
        : day{ day }, month{ month }, year{ year }
    {}
    Date(int year) : Date(1, 1, year)
    {}
    friend void displayDate(Date date);
};

void displayDate(Date date)
{
    std::cout << date.day << "." << date.month << "." << date.year << std::endl;
}

Date baseDate()
{
    return 2000;
}

int main()
{
    displayDate(2024);

    Date date = 2014;
    displayDate(date);

    Date date2000 = baseDate();
    displayDate(date2000);

    getchar();
    return 0;
}
