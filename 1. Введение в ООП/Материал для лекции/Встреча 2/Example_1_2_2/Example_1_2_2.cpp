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

    // определение объекта
    Student student;

    cout << "После вызова конструктора" << endl << endl;

    // присвоение значений объекту
    student.setName("Петров А.И.");
    student.setMark(10, 0);
    student.setMark(10, 1);
    student.setMark(9, 2);

    // выполнение метода объекта
    cout << "Средний балл " << student.getName()
        << " : " << fixed << setprecision(2)
        << student.getAver() << endl;

    _getch();
    return 0;
}