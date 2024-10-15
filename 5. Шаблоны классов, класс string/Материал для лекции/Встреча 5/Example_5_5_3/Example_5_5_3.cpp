#include <iostream>

#include <string> //1. Для подключения

int main()
{
    //2. Нужно пространство имён std::

    //3. У строк происходит автоматическая инициализация 0
    std::string text1;
    int number{};
    std::cout << "|" << number << "|" << text1 << "|" << std::endl;

    //4. Разные види инициализация
    std::string text2{ "Hello" }; // строка из const char*
    std::string name(8, 'a'); // строка из 8 'a' символов
    std::string month = "March"; // то же, что string month{"March"};

    //5. Нет завершающего нулевого символа.
    char stringC[]{ 'a', 'b', 'c', '\0', 'c', 'b', 'a' }; // Не все символы учтутся.
    std::string stringCPP{ 'a', 'b', 'c', '\0', 'c', 'b', 'a' }; //\0 как обычный символ
    std::cout << " |" << stringC << "|" << std::endl;
    std::cout << " |" << stringCPP << "|" << std::endl;

    //6. Длина строки
    std::cout << stringCPP.size() << std::endl;
    int len = name.length();
    std::cout << len << std::endl;

    //7. Доступ к отдельным символам строки через оператор
    char ch = name[3];
    for (int i = 0; i < name.length(); i++)
    {
        std::cout << name[i];
    }

    std::cout << std::endl;
    
    for (auto c : name)
    {
        std::cout << c;
    }
}