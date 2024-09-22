#include <iostream>
#include <conio.h>
#include <iomanip>

#include "Array.h"
using namespace std;

// конструктор по умолчанию - 10 элементов
Array::Array(int aSize)
    : size{ aSize }, arr{ new int[size] {} }
{
}

// конструктор копирования
Array::Array(const Array& a)
    : size{ a.size }, arr{ new int[size] }
{
    for (int i = 0; i < size; ++i)
    {
        arr[i] = a.arr[i];
    }
}

Array::~Array()
{
    delete[] arr;
}

int Array::length() const
{
    return size;
}

const Array& Array::operator=(const Array& a)
{
    if (&a != this)
    {
        if (size != a.size)
        {
            delete[] arr;
            size = a.size;
            arr = new int[size];
        }

        for (int i = 0; i < size; ++i)
        {
            arr[i] = a.arr[i];
        }
    }

    return *this;
}

bool Array::operator==(const Array& a) const
{
    if (size != a.size)
    {
        return false;
    }

    for (int i{ 0 }; i < size; ++i) {
        if (arr[i] != a.arr[i]) {
            return false;
        }
    }

    return true;
}

bool Array::operator!=(const Array& a) const
{
    return !(*this == a);
}

int& Array::operator[](int index)
{
    if (index < 0 || index >= size)
    {
        cout << "Out of range" << endl;
        _getch();
        exit(1);
    }

    return arr[index];
}

int Array::operator[](int index) const
{
    if (index < 0 || index >= size)
    {
        cout << "Out of range" << endl;
        _getch();
        exit(1);
    }

    return arr[index];
}

istream& operator>>(istream& input, Array& a)
{
    for (size_t i{ 0 }; i < a.size; ++i) {
        input >> a.arr[i];
    }

    return input;
}

ostream& operator<<(ostream& output, const Array& a)
{
    for (int i{ 0 }; i < a.size; ++i) {
        output << a.arr[i] << "  ";
    }

    output << endl;
    return output;
}
