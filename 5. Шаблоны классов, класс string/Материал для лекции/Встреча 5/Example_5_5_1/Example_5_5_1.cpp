#include <iostream>

int main()
{
    char ch{ 'a' }; // исходный для хранения символов (ASCII)
    char8_t ch8{ u8'a' }; // требуется версия C++ 20
    char16_t ch16{ u'a' };
    char32_t ch32{ U'a' };
    wchar_t chw{ L'a' }; // нестандартный тип компилятора Microsoft

    //Хранение данных для каждого из типов:
    std::string ch, ch8;
    std::u16string ch16;
    std::u32string ch32;
    std::wstring chw;
}