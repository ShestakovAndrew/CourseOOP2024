#include <iostream>
#include <string.h>
#include <time.h>

using namespace std;

class QueueRing
{
public:

	QueueRing(int m);

	void Add(int elem); //Добавление элемента

	bool Extract(); //Извлечение элемента

	void Clear(); //Очистка очереди

	bool IsEmpty(); //Проверка очереди на пустоту

	bool IsFull(); //Проверка на переполнение очереди

	int GetCount(); //Количество элементов в очереди

	void Show(); //демонстрация очереди

	~QueueRing();

private:
	int* m_queue; //Очередь
	int m_maxQueueLength; //Максимальный размер очереди
	int m_currentQueueLength; //Текущий размер очереди
};

void QueueRing::Show() {
	cout << "\n-----------------------------------\n";
	//демонстрация очереди
	for (int i = 0; i < m_currentQueueLength; i++) {
		cout << m_queue[i] << " ";
	}
	cout << "\n-------------------------------------\n";
}
QueueRing::~QueueRing()
{
	//удаление очереди
	delete[] m_queue;
}
QueueRing::QueueRing(int m)
{
	//получаем размер
	m_maxQueueLength = m;
	//создаем очередь
	m_queue = new int[m_maxQueueLength];
	//Изначально очередь пуста
	m_currentQueueLength = 0;
}
void QueueRing::Clear()
{
	//Эффективная "очистка" очереди
	m_currentQueueLength = 0;
}
bool QueueRing::IsEmpty()
{
	//Пуст?
	return m_currentQueueLength == 0;
}
bool QueueRing::IsFull()
{
	// Полон?
	return m_currentQueueLength == m_maxQueueLength;
}
int QueueRing::GetCount()
{
	//Количество присутствующих в стеке элементов
	return m_currentQueueLength;
}
void QueueRing::Add(int c)
{
	//Если в очереди есть свободное место,
	//то увеличиваем количество
	//значений и вставляем новый элемент
	if (!IsFull())
		m_queue[m_currentQueueLength++] = c;
}
bool QueueRing::Extract()
{
	//Если в очереди есть элементы, то возвращаем тот,
	//который вошел первым и сдвигаем очередь
	if (!IsEmpty()) {
		//запомнить первый
		int temp = m_queue[0];
		//сдвинуть все элементы
		for (int i = 1; i < m_currentQueueLength; i++)
			m_queue[i - 1] = m_queue[i];
		//забрасываем первый "вытолкнутый элемент
		//в конец"
		m_queue[m_currentQueueLength - 1] = temp;
		return 1;
	}
	else return 0;
}
void main()
{
	srand(time(0));
	//создание очереди
	QueueRing QUR(25);
	//заполнение части элементов
	for (int i = 0; i < 5; i++) 
	{
		QUR.Add(rand() % 50);
	}
	//показ очереди
	QUR.Show();
	//извлечение элемента
	QUR.Extract();
	//показ очереди
	QUR.Show();
}