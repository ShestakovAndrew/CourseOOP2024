#include <iostream>

class BadOrder
{
    int fieldOne;
    int fieldTwo;
public:
    BadOrder(int param) : fieldTwo{ param }, fieldOne{ fieldTwo + 10 } {}
    void print()
    {
        std::cout << "fieldOne = " << fieldOne << '\n'
            << "fieldTwo = " << fieldTwo << '\n';
    }
};

class GoodOrder
{
    int fieldOne;
    int fieldTwo;
public:
    GoodOrder(int param) : fieldOne{ param + 10 }, fieldTwo{ param } {}
    void print()
    {
        std::cout << "fieldOne = " << fieldOne << '\n'
            << "fieldTwo = " << fieldTwo << '\n';
    }
};

int main()
{
    std::cout << "BadOrder\n";
    BadOrder t1{ 42 };
    t1.print();

    std::cout << "GoodOrder\n";
    GoodOrder t2{ 33 };
    t2.print();

    return 0;
}