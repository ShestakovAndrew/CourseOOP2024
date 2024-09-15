#include <iostream>

class Fraction
{
    int numerator;
    int denominator;
public:
    Fraction(int num, int denom)
        : numerator{ num }, denominator{ denom }
    {
        std::cout << "Fraction constructed for " << this << '\n';
    }
    Fraction() : Fraction(1, 1) {}
    Fraction(const Fraction& fract)
        : numerator{ fract.numerator }, denominator{ fract.denominator }
    {
        std::cout << "Fraction copy constructed for " << this << '\n';
    }
    ~Fraction() { std::cout << "Fraction destructed for " << this << '\n'; }
    void print()
    {
        std::cout << '(' << numerator << " / " << denominator << ")";
    }
};

int main()
{
    /*Создаем и инициализируем временным, анонимным экземпляром Fraction - a.
    Конструктор копирования не вызовется, временный объект не создастся!
    Компилятор непосредственно проинициализирует экземпляр a значениями 4 и 6.
    */

    Fraction a{ Fraction{4,6} };

    std::cout << "a = ";
    a.print();
    std::cout << '\n';

    return 0;
}