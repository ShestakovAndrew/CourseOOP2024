// Вычислить среднюю оценку студента

#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

// определение класса Студент
class Student
{
public:
    // ФИО
    char name[21];
    // оценки
    int marks[3];
    // вычисление среднего балла
    double getAver();
};


int main()
{
    setlocale(LC_ALL, "");
    cout << "Успеваемость студента."
        << endl << endl;

    // определение объекта
    Student student;

    // присвоение значений объекту
    strcpy_s(student.name, 20, "Петров А.И");
    student.marks[0] = 10;
    student.marks[1] = 10;
    student.marks[2] = 9;

    // выполнение метода объекта
    double aver = student.getAver();

    cout << "Средний балл " << student.name
        << " : " << fixed << setprecision(2)
        << aver << endl;

    _getch();
    return 0;
}

double Student::getAver()
{
    double sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += marks[i];
    }
    return sum / 3;
}
