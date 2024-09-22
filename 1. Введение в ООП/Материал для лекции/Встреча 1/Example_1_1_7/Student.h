#pragma once

class Student
{
private:
    // ФИО
    char name[21];
    // оценки
    int marks[3];
public:
    // вычисление среднего балла
    double getAver();

    // доступ к полю name
    const char* getName();
    void setName(const char* studentName);
    // доступ к элементам массива marks
    int getMark(int index);
    void setMark(int mark, int index);
};

