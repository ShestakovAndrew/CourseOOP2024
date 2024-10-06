#pragma once
#include <iostream>

void stopProgram(std::string message);

template<class T>
class Array
{
	static const size_t size{ 5 };
	T arr[size];

public:
	Array();
	int getSize() const;
	T getItem(size_t index) const;
	void setItem(size_t index, T value);
	void display();
	void sort();
};

template<class T>
Array<T>::Array()
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = T();
	}
}

template<class T>
int Array<T>::getSize() const
{
	return size;
}

template<class T>
T Array<T>::getItem(size_t index) const
{
	if (index >= 0 && index < size)
	{
		return arr[index];
	}
	else
	{
		stopProgram("Index is out of range!");
	}
}

template<class T>
void Array<T>::setItem(size_t index, T value)
{
	if (index >= 0 && index < size)
	{
		arr[index] = value;
	}
	else
	{
		stopProgram("Index is out of range!");
	}
}

template<class T>
void Array<T>::display()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template<class T>
void Array<T>::sort()
{
	for (int k = size - 1; k > 0; k--)
	{
		for (int j = 0; j < k; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}


