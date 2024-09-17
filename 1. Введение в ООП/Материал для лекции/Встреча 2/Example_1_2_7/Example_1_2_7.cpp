// Вычислить среднюю оценку студентов

#include <iostream>
#include <iomanip>
#include <conio.h>
#include "Student.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    cout << "Успеваемость студентов."
        << endl << endl;

    // размер массива объектов
    const int size = 2;

    // создание и инициализация 
    // динамического массива объектов
    Student* students = new Student[size]
    {
        {"Студент 1", 3, new int[3] { 10, 10, 9 }},
        {"Студент 2", 3, new int[3] { 8, 10, 8 }}
    };

    // работа с массивом объектов
    double sum = 0;
    for (Student* stud = students;
        stud < students + size; stud++)
    {
        double aver = stud->getAver();
        cout << "Средний балл " << stud->getName()
            << " : " << fixed << setprecision(2)
            << aver << endl;
        sum += aver;
    }

    cout << endl;
    cout << "Средний балл по группе: "
        << " : " << fixed << setprecision(2)
        << sum / size << endl;

    delete[] students;
    _getch();
    return 0;
}

