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
			<< " elements, for " << this << std::endl;
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
			<< std::endl;
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
	
	//int getElem(int idx) const { return arr[idx]; }
	//void setElem(int idx, int val) { arr[idx] = val; }

	// константная перегрузка, возвращающая элемент
	// по значению
	int operator[](int idx) const
	{
		assert(idx >= 0 && idx < size && "Index is out of range!");
		return arr[idx];
	}
	
	// не константная перегрузка, возвращающая элемент
	// по ссылке
	int& operator[](int idx)
	{
		assert(idx >= 0 && idx < size && "Index is out of range!");
		return arr[idx];
	}
	
	void print() const;
	void randomize();
	
	~DynArray()
	{
		std::cout << "Try to free memory from DynArray for" << arr << " pointer" << std::endl;
		delete[] arr;
		std::cout << "DynArr destructed for " << size << " elements, for " << this << std::endl;
	}
};

void DynArray::print() const
{
	for (int i{ 0 }; i < size; ++i)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}

void DynArray::randomize()
{
	for (int i{ 0 }; i < size; ++i)
	{
		arr[i] = rand() % 10;
	}
}

DynArray CreateRandomDynArray(int arrSize)
{
	DynArray arr{ arrSize };
	arr.randomize();
	return arr;
}

int main()
{
	const int arrSize{ 10 };
	DynArray ar1{ CreateRandomDynArray(arrSize) };
	
	std::cout << "ar1 elements : " << std::endl;
	ar1.print();
	std::cout << std::endl << "Change every ar1 element to its square:" << std::endl;
	
	for (int i{ 0 }; i < arrSize; ++i)
	{
		ar1[i] *= ar1[i];
		std::cout << "ar1[" << i << "] = " << ar1[i] << std::endl;
	}
	
	const DynArray ar2{ CreateRandomDynArray(arrSize) };

	std::cout << "ar2 elements :" << std::endl;
	for (int i{ 0 }; i < arrSize; ++i)
	{
		std::cout << "ar2[" << i << "] = " << ar2[i] << std::endl;
	}

	return 0;
}