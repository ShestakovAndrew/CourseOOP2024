#include <iostream>
#include <string.h>
#include <time.h>

using namespace std;

class Queue
{
public:

	Queue(int m);

	void Add(int elem); //Добавление элемента

	int Extract(); //Извлечение элемента

	void Clear(); //Очистка очереди

	bool IsEmpty(); //Проверка очереди на пустоту

	bool IsFull(); //Проверка на переполнение очереди

	int GetCount(); //Количество элементов в очереди

	void Show(); //демонстрация очереди

	~Queue();

private:
	int* m_queue; //Очередь
	int m_maxQueueLength; //Максимальный размер очереди
	int m_currentQueueLength; //Текущий размер очереди
};

void Queue::Show() 
{
	cout << "\n-----------------------------------\n";
	for (int i = 0; i < m_currentQueueLength; i++) {
		cout << m_queue[i] << " ";
	}
	cout << "\n-----------------------------------\n";
}

Queue::~Queue()
{
	delete[] m_queue;
}

Queue::Queue(int queueLength)
{
	//получаем размер
	m_maxQueueLength = queueLength;
	//создаем очередь
	m_queue = new int[m_maxQueueLength];
	//Изначально очередь пуста
	m_currentQueueLength = 0;
}

void Queue::Clear()
{
	//Эффективная "очистка" очереди
	m_currentQueueLength = 0;
}
bool Queue::IsEmpty()
{
	return m_currentQueueLength == 0;
}
bool Queue::IsFull()
{
	return m_currentQueueLength == m_maxQueueLength;
}
int Queue::GetCount()
{
	//Количество присутствующих в стеке элементов
	return m_currentQueueLength;
}
void Queue::Add(int elem)
{
	//Если в очереди есть свободное место,
	//то увеличиваем количество
	//значений и вставляем новый элемент
	if (!IsFull())
	{
		m_queue[m_currentQueueLength++] = elem;
	}
}
int Queue::Extract()
{
	//Если в очереди есть элементы, то возвращаем тот,
	//который вошел первым и сдвигаем очередь
	if (!IsEmpty()) 
	{
		//запомнить первый
		int temp = m_queue[0];
		//сдвинуть все элементы
		for (int i = 1; i < m_currentQueueLength; i++)
		{
			m_queue[i - 1] = m_queue[i];
		}
		//уменьшить количество
		m_currentQueueLength--;
		//вернуть первый(нулевой)
		return temp;
	}
	else //Если в стеке элементов нет
	{
		return -1;
	}
}
void main()
{
	srand(time(0));
	//создание очереди
	Queue QU(25);
	//заполнение части элементов
	for (int i = 0; i < 5; i++) 
	{
		QU.Add(rand() % 50);
	}
	//показ очереди
	QU.Show();
	//извлечение элемента
	QU.Extract();
	//показ очереди
	QU.Show();
}