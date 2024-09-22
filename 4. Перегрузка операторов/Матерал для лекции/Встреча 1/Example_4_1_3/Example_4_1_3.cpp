#include <iostream>
#include <conio.h>
using namespace std;

class Name
{
    char* firstName;
    char* secondName;

    void setCharArray(char*& dest, const char* source)
    {
        int strSize = strlen(source) + 1;
        dest = new char[strSize];
        strcpy_s(dest, strSize, source);
    }

    void remove()
    {
        if (firstName != nullptr)
        {
            delete[] firstName;
        }

        if (secondName != nullptr)
        {
            delete[] secondName;
        }
    }

public:
    Name()
    {
        firstName = nullptr;
        secondName = nullptr;
    }

    Name(const char* fName, const char* sName)
    {
        setCharArray(firstName, fName);
        setCharArray(secondName, sName);
    }

    Name(const Name& name)
    {
        setCharArray(firstName, name.firstName);
        setCharArray(secondName, name.secondName);
    }
    ~Name()
    {
        remove();
    }

    void write()
    {
        cout << firstName << " " << secondName << endl;
    }
};

void writeLine(Name name)
{
    name.write();
}

int main()
{
    setlocale(LC_ALL, "");

    char firstName[10] = "John";
    char secondName[10] = "Smith";

    {
        Name name(firstName, secondName);
        cout << "Выполнен конструктор объекта name: ";
        name.write();
    }
    cout << "Выполнен деструктор объекта name" << endl << endl;

    {
        Name name(firstName, secondName);
        cout << "Выполнен конструктор объекта name: ";

        writeLine(name);
        cout << "Выполнено копирование объекта name: ";
        name.write();
    }
    cout << "Выполнен деструктор объекта name" << endl << endl;

    Name aName;
    {
        Name name(firstName, secondName);
        cout << "Выполнен конструктор объекта name: ";
        name.write();
        aName = name;
        cout << "Выполнено присваивание объекта aName: ";
        aName.write();
    }
    cout << "Выполнен деструктор объекта name" << endl << endl;

    cout << "Выполняется обращение к объекту aName: ";
    aName.write();

    _getch();
    return 0;
}
