#include <iostream>
#include "Student.h"
using namespace std;

// ������ �����
void Student::setName(const char* studentName)
{
    // ������������ � ��������� �����
    strcpy_s(name, 20, studentName);
}

// ������ ��������� ������� marks
void Student::setMark(int mark, int index)
{
    // ������������ � ��������� ������
    if (mark < 1 or mark > 12)
    {
        mark = 0;
    }
    marks[index] = mark;
}

// ���������� ������ ���������� �������� �����
double Student::getAver()
{
    double sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += marks[i];
    }
    return sum / 3;
}

