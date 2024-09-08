#pragma once

class Student
{
private:
    // ���
    char* name;
    // ����� ������
    int markCount;
    // ������
    int* marks;

    // ��������� �������
    void createName(const char* studentName);

public:
    // ������������
    Student();

    Student(const char* studentName,
        const int studentMarkCount);

    Student(const char* studentName,
        const int studentMarkCount,
        const int* studentMarks);

    // ����������
    ~Student();

    // ������ �������� ������ ������
    const char* getName()
    {
        return name;
    }

    int getMark(int index)
    {
        return marks[index];
    }

    // ������ �������� ������ ������
    void setName(const char* studentName);
    void setMark(int mark, int index);

    // ���������� �������� �����
    double getAver();
};