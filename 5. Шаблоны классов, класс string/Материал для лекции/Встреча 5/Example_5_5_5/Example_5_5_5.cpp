#include <iostream>
#include <string>

int main()
{
	/*
	Классификация методов класса string:

	■ методы доступа к элементам;
	■ методы - итераторы;
	■ методы поиска;
	■ методы редактирования;
	■ методы работы со вместимостью;
	■ сервисные функции(не члены класса).
	*/

	//1. Методы доступа к элементам:
	{
		std::string name{ "12345" };

		// at()
		char c2 = name.at(10); //Выбрасывает исключение => Более безопасно
		char c1 = name[10];

		// front() back()
		char& beg = name.front(); //первый элемент
		char& fin = name.back(); //второй элемент

		// data() - конвертация в СИ-строку
		const char* pname = name.data();
	}

	//2. Методы - итераторы:
	{
		//Методы — итераторы возвращают указатели на элементы строки.

		//begin(), cbegin() - на первый элемент
		//end(), cend() - на следующий за последним (несуществующий)
		//rbegin(), rend(), crbegin(), crend() - реверсивные итераторы

		std::string text{ "this is a c++ string" };
		for (auto it = text.begin(); it < text.end(); it++)
		{
			if (!isalpha(*it) && !isspace(*it))
			{
				std::cout << *it;
			}
		}
		std::cout << std::endl;
	}

	//3. Методы поиска:
	{
		//Методы — итераторы возвращают указатели на элементы строки.
		std::string text{ "This is a c++ string" };
		// find() - первая подстрака с указанной позиции.
		// rfind() - последняя подстрака с указанной позицией 
		std::cout << " " << text << std::endl;
		std::cout << " " << text.find("is") << std::endl;// 1 — find (2)
		std::cout << " " << text.find("is", 4) << std::endl;// 2 — find (2)
		std::cout << " " << text.rfind("is") << std::endl;// 3 — rfind (2)
		std::cout << " " << text.rfind("is", 4) << std::endl;// 4 — rfind (2)
		std::cout << " " << text.find("strong", 0, 3) << std::endl;// 5 — find (4)
		std::cout << " " << text.find("strong") << std::endl;// 6 — find (4)
		// find_first_of() - первый найденный символ из подстроки
		// find_last_of() - последний найденный символ из подстроки
		std::cout << " " << text << std::endl;
		std::cout << " " << text.find_first_of("bac") << std::endl; // 1
		std::cout << " " << text.find_last_of("bac") << std::endl; // 2
		// find_first_not_of() - первый найденный символ не из подстроки
		// find_last_not_of() - последний найденный символ не из подстроки
		std::cout << " " << text << std::endl;
		std::cout << " " << text.find_first_not_of("abcdefghijklmnopqrstuvwxyz") << std::endl;

		//Если поиск не удался то string::npos
	}

	//4. Методы редактирования, изменения строк:
	{
		// assign() - для замещения
		std::string text{ "this is a c++ string" };
		std::string str1{ "next string" };
		std::cout << " " << text.assign(str1) << std::endl;
		std::cout << " " << text.assign(str1, 3, 4) << std::endl;
		std::cout << " " << text.assign("abcdef") << std::endl;
		std::cout << " " << text.assign("abcdef", 2) << std::endl;
		std::cout << " " << text.assign(5, 'a') << std::endl;

		// clear() - для удаления содержимого
		std::string textDel{ "this is a c++ string" };
		textDel.clear();
		std::cout << textDel;

		// erase() - для удаления части содержимого
		std::string str2 = text;
		std::cout << " " << "|" << str2.erase() << "|" << std::endl;
		str2 = text;
		std::cout << " " << "|" << str2.erase(3, 10) << "|" << std::endl;
		str2 = text;
		str2.erase(str2.begin() + 1);
		std::cout << " " << "|" << str2 << "|" << std::endl;
		str2 = text;
		str2.erase(str2.begin() + 1, str2.end() - 3);
		std::cout << " " << "|" << str2 << "|" << std::endl;

		// insert() - для вставки по позиции
		std::string theStr{ "abcdef" };
		std::string str3 = text;
		std::cout << " " << str3.insert(5, theStr) << std::endl;
		str3 = text;
		std::cout << " " << str3.insert(5, theStr, 2, 3) << std::endl;
		str3 = text;
		str3.insert(str3.begin() + 2, 'A');
		std::cout << " " << str3 << std::endl;

		// push_back() - для добавления в конец;
		std::string str4 = text;
		std::cout << str4 << std::endl;
		str4.push_back('F');
		std::cout << str4 << std::endl;

		// pop_back() - удаляет последний символ строки;
		std::string str5 = text;
		std::cout << str5 << std::endl;
		str5.pop_back();
		std::cout << str5 << std::endl;

		// append() - добавляет в конец строки указанные символы
		std::string str6_1 = text;
		std::string str6_2 = text;
		std::cout << str6_1.append(str6_2) << std::endl;

		// replace() - заменяет часть строки на заданную строку
		std::string str6{ "abcdef" };
		std::string txt = text;
		txt.replace(10, 3, str6);
		std::cout << " " << txt << std::endl;
		txt = text;
		txt.replace(10, 3, str6, 2, 2);
		std::cout << " " << txt << std::endl;
		txt = text;
		txt.replace(10, 3, "new");
		std::cout << " " << txt << std::endl;
		txt = text;
		txt.replace(10, 3, "1234", 1, 2);
		std::cout << " " << txt << std::endl;
		txt = text;
		txt.replace(10, 3, 3, '!');
		std::cout << " " << txt << std::endl;
		txt = text;
		txt.replace(txt.begin() + 10, txt.end() - 7, str6);
		std::cout << " " << txt << std::endl;

		// substr() - Возвращает новую строку  — подстроку данной строки
		std::cout << " " << text.substr(5, 9) << std::endl;
		std::cout << " " << text.substr(5) << std::endl;
		std::cout << " " << text << std::endl;

		// copy() - Копирует подстроку данной строки
		std::string str7 = text;
		char carr[10]{ 0 };
		str7.copy(carr, 8, 5);
		std::cout << " " << carr << std::endl;

		// resize() - Устанавливает размер строки равным заданному числу n.
		std::string str8{ "abcdef" };
		str8.resize(10, '*');
		std::cout << " " << str8 << std::endl;

		// swap() - Обменивает строку с другой строкой
		std::string str9{ "this is a c++ string" };
		std::string str10{ "abcdef" };
		str9.swap(str10);
		std::cout << " " << str9 << std::endl;
		std::cout << " " << str10 << std::endl;
	}

	//5. методы работы со вместимостью:
	{
		// empty() - Проверка на пустоту
		// size(), length() - Возвращает количество символов в строке
		// capacity() - Возвращает емкость строки
		// max_size() - Возвращает максимально возможную длину строки
		// reserve() - Функция задает новую емкость строки n
		// shrink_to_fit() - Функция сокращает емкость строки, делая ее равной длине строки
		std::string text{ "this is a c++ string" };
		std::string str{ "abcdef" };
		std::string none;

		std::cout << " " << text.length() << std::endl;
		std::cout << " " << text.size() << std::endl;
		std::cout << " " << text.capacity() << std::endl;
		std::cout << " " << text.max_size() << std::endl;
		std::cout << " " << str.length() << std::endl;
		std::cout << " " << str.capacity() << std::endl;
		std::cout << " " << str.max_size() << std::endl;
		std::cout << " " << none.length() << std::endl;
		std::cout << " " << none.capacity() << std::endl;

		text.reserve(8);
		std::cout << text << std::endl;
		std::cout << " " << text.capacity() << std::endl;

		text.shrink_to_fit();
		std::cout << " " << text.capacity() << std::endl;
	}

	//6. Cервисные функции:
	{
		//Сервисные функции предназначены для преобразований строковых 
		//данных и для чтения строк с пробельными символами.

		// getline() - Считывает строку из входного потока
		std::string text;
		std::getline(std::cin, text);

		// stoi(), stol(), stoll() - Функции преобразуют строку str в целое число
		std::string text1{ "129" };
		int number1 = stoi(text1);
		std::cout << " " << number1 << std::endl;

		size_t pos;
		std::string text2{ "124,8" };
		int number2 = stoi(text2, &pos);
		std::cout << " " << number2 << std::endl;
		std::cout << " " << pos << std::endl;

		std::string text3{ "1248" };
		int number3 = stoi(text3, &pos, 8);
		std::cout << " " << number3 << std::endl;
		std::cout << " " << pos << std::endl;

		// stoul(), stoull() - Функции преобразуют строку str в положительные (unsigned) целые числа
		unsigned int number1 = stoul(text1);
		unsigned long number2 = stoul(text2);
		
		// stof(), stod(), stold() - Функции преобразуют строку str в числа с плавающей запятой.
		std::string orbits("365.24 29.53");
		size_t sz;
		double earthTurn = stod(orbits, &sz);
		double moonTurn = stod(orbits.substr(sz));
		std::cout << "The moon completes " << (earthTurn / moonTurn)
			<< " orbits per Earth year" << std::endl;

		// to_string() - Преобразует числа в строку
		std::string piIs = "Pi is " + std::to_string(3.1415926);
		std::cout << " " << piIs << std::endl;
	}
}