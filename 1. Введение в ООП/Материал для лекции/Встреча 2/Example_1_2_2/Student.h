#pragma once

class Student
{
private:
    // ФИО
    char name[21];
    // оценки
    int marks[3];
public:
    // конструктор
    Student()
    {
        std::cout << "Конструктор Student"
            << std::endl;
    }

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