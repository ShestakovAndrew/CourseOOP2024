#pragma once

class Student
{
private:
    // ФИО
    char* name;
    // число оценок
    int markCount;
    // оценки
    int* marks;

    // служебные функции
    void createName(const char* studentName);

public:
    // конструктор
    Student(const char* studentName,
        const int studentMarkCount, const int* studentMarks);

    // чтение закрытых членам класса
    const char* getName()
    {
        return name;
    }

    int getMark(int index)
    {
        return marks[index];
    }

    // запись закрытых членам класса
    void setName(const char* studentName);
    void setMark(int mark, int index);

    // вычисление среднего балла
    double getAver();
};