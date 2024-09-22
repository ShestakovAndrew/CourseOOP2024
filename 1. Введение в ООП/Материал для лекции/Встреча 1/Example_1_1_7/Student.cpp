#include <iostream>
#include "Student.h"
using namespace std;

// реализация метода вычисления среднего балла
double Student::getAver()
{
    double sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += marks[i];
    }
    return sum / 3;
}

// доступ к полю name 
// без возможности его изменения
const char* Student::getName()
{
    return name;
}

void Student::setName(const char* studentName)
{
    // присваивание с проверкой длины
    strcpy_s(name, 20, studentName);
}

// доступ к элементам массива marks
int Student::getMark(int index)
{
    return marks[index];
}

void Student::setMark(int mark, int index)
{
    // присваивание с проверкой оценки
    if (mark < 1 or mark > 12)
    {
        mark = 0;
    }
    marks[index] = mark;
}

