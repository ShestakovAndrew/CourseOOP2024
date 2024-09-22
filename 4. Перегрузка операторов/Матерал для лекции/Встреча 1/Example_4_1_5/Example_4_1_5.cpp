#include <iostream>
#include <conio.h>
#include "Array.h"
using namespace std;

int main() {
    Array array1{ 5 };
    Array array2;

    for (int i = 0; i < 5; i++)
    {
        array1[i] = i;
    }

    for (int i = 0; i < 10; i++)
    {
        array2[i] = i + 11;
    }

    cout << "Size of array1: " << array1.length() << endl;
    cout << "Array1: " << array1 << endl;

    cout << "Size of array2: " << array2.length() << endl;
    cout << "Array2: " << array2 << endl;

    cout << "(array1 == array2) ?" << endl;
    if (array1 == array2)
    {
        cout << "array1 == array2" << endl << endl;;
    }
    else
    {
        cout << "array1 != array2" << endl << endl;;
    }

    cout << "Array array3{ array1 }; // copy constructor" << endl;
    Array array3{ array1 }; // конструктор копирования
    cout << "Size of array3: " << array3.length() << endl;
    cout << "Array3: " << array3 << endl;

    cout << "array1 = array2;        // assignment operator" << endl;
    array1 = array2;        // операция присваивания
    cout << "Array1: " << array1;
    cout << "Array2: " << array2 << endl;

    cout << "array2[5] = 1000;" << endl;
    array2[5] = 1000;
    cout << "Array2: " << array2 << endl;

    cout << "array2[15] = 1000;" << endl;
    array2[15] = 1000; // ошибка: индекс за пределами массива

    _getch();
    return 0;
}
