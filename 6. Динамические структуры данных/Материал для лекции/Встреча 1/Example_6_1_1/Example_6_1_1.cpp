#include <iostream>
#include <string.h>
#include <time.h>

using namespace std;

class Stack
{
	enum { EMPTY = -1, FULL = 20 }; //Нижняя и верхняя границы стека

	char m_stack[FULL + 1]; //Массив для хранения данных

	int m_top; //Указатель на вершину стека

public:

	Stack(); //Конструктор

	void Push(char c); //Добавление элемента

	char Pop(); //Извлечение элемента

	void Clear(); //Очистка стека

	bool IsEmpty(); //Проверка существования элементов в стеке

	bool IsFull(); //Проверка на переполнение стека

	int GetCount(); //Количество элементов в стеке
};

Stack::Stack()
{
	//Изначально стек пуст
	m_top = EMPTY;
}

void Stack::Clear()
{
	//Эффективная "очистка" стека
	//(данные в массиве все еще существуют,
	//но функции класса, ориентированные
	//на работу с вершиной стека,
	//будут их игнорировать)
	m_top = EMPTY;
}

bool Stack::IsEmpty()
{
	return m_top == EMPTY;
}

bool Stack::IsFull()
{
	return m_top == FULL;
}

int Stack::GetCount()
{
	//Количество присутствующих в стеке элементов
	return m_top + 1;
}

void Stack::Push(char c)
{
	//Если в стеке есть место, то увеличиваем указатель
	//на вершину стека и вставляем новый элемент
	if (!IsFull())
	{
		m_stack[++m_top] = c;
	}
}

char Stack::Pop()
{
	//Если в стеке есть элементы, то возвращаем
	//верхний и уменьшаем указатель на вершину стека
	return IsEmpty() ? 0 : m_stack[m_top--];
}

void main()
{
	srand(time(0));
	Stack ST;
	char c;

	//пока стек не заполнится
	while (!ST.IsFull()) 
	{
		c = rand() % 4 + 2;
		ST.Push(c);
	}

	//пока стек не освободится
	while (c = ST.Pop()) 
	{
		cout << c << " ";
	}
	cout << "\n\n";
}