#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

// определение класса 
class Student
{
public:
    string name;
    vector<size_t> marks;
};

int main()
{
    setlocale(LC_ALL, "");

    cout << "Успеваемость студента." << endl << endl;

    // определение объекта
    Student student;

    // присвоение значений объекту
    student.name = "Петров А.И";
    student.marks = vector<size_t>(10, 20);

    // получение значений объекта
    cout << student.name << " : " << student.marks[0] << endl;

    _getch();
    return 0;
}
