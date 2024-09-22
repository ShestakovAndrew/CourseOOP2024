#include <iostream>
#include <cassert>
class DynArray
{
	int* arr;
	int size;
public:
	DynArray(int sizeP)
		: arr{ new int[sizeP] {} }, size{ sizeP }
	{
		std::cout << "DynArr constructed for " << size
			<< " elements, for " << this << '\n';
	}
	DynArray() : DynArray(5) {}
	DynArray(DynArray& object) = delete;
	DynArray& operator=(DynArray& object) = delete;
	DynArray(DynArray&& object)
		: arr{ object.arr }, size{ object.size }
	{
		object.arr = nullptr;
		object.size = 0;
		std::cout << "DynArr move constructed for "
			<< size << " elements, for " << this
			<< '\n';
	}
	DynArray& operator=(DynArray&& object)
	{
		if (!(this == &object))
		{
			delete arr;
			arr = object.arr;
			size = object.size;
			object.arr = nullptr;
			object.size = 0;
		}
		std::cout << "DynArr move assigned for "
			<< size << " elements, for " << this
			<< '\n';
		return *this;
	}
	// константная перегрузка, возвращающая элемент
	// по значению
	int operator[](int idx)const
	{
		assert(idx >= 0 and idx < size and "Index is out "
			"of range!");
		return arr[idx];
	}
	// не константная перегрузка, возвращающая элемент
	// по ссылке
	int& operator[](int idx)
	{
		assert(idx >= 0 and idx < size and "Index is out"
			"of range!");
		return arr[idx];
	}
	void print()const;
	void randomize();
	~DynArray()
	{
		std::cout << "Try to free memory from DynArray for"
			<< arr << " pointer\n";
		delete[] arr;
		std::cout << "DynArr destructed for " << size
			<< " elements, for " << this << '\n';
	}
};
void DynArray::print()const
{
	for (int i{ 0 }; i < size; ++i)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}
void DynArray::randomize()
{
	for (int i{ 0 }; i < size; ++i)
	{
		arr[i] = rand() % 10;
	}
}
DynArray arrayFactory(int arrSize)
{
	DynArray arr{ arrSize };
	arr.randomize();
	return arr;
}
int main()
{
	const int arrSize{ 10 };
	DynArray ar1{ arrayFactory(arrSize) };
	std::cout << "ar1 elements : ";
	ar1.print();
	std::cout << "\nChange every ar1 element to its "
		"square:\n";
	for (int i{ 0 }; i < arrSize; ++i)
	{
		ar1[i] *= ar1[i];
		std::cout << "ar1[" << i << "] = " << ar1[i] << '\n';
	}
	const DynArray ar2{ arrayFactory(arrSize) };
	std::cout << "ar2 elements :\n";
	for (int i{ 0 }; i < arrSize; ++i)
	{
		std::cout << "ar2[" << i << "] = " << ar2[i] << '\n';
	}
	return 0;
}