// Вычислить среднюю оценку студента

#include <iostream>
#include <iomanip>
#include <conio.h>
#include "Student.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    cout << "Успеваемость студента."
        << endl << endl;

    // создание объекта с заданными значениями
    Student student("Петров А.И.", 3,
        new int[3] { 10, 10, 9 });

    // выполнение метода объекта
    cout << "Средний балл " << student.getName()
        << " : " << fixed << setprecision(2)
        << student.getAver() << endl;

    _getch();
    return 0;
}

