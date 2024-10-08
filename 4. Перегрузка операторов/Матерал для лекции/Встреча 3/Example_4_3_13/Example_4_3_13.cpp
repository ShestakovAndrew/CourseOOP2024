﻿#include <iostream>

template <typename T>
void print(T* begin, T* end, char delimiter = ' ')
{
	while (begin != end)
	{
		std::cout << *begin++ << delimiter;
	}
	std::cout << '\n';
}

template <typename T, typename Predicate>
int copy_if(T* srcB, T* srcE, T* destB, T* destE, Predicate pred)
{
	int copyCount{ 0 };
	while (destB != destE and srcB != srcE)
	{
		if (pred(*srcB))
		{
			*destB++ = *srcB;
			++copyCount;
		}
		++srcB;
	}
	return copyCount;
}

class SumLimit
{
	int sumLimit;
	int sum;
public:
	SumLimit(int sumLimitP, int startSumP) : sumLimit{ sumLimitP }, sum{ startSumP } {}
	SumLimit(int sumLimitP) : SumLimit{ sumLimitP, 0 } {}

	bool operator()(int el)
	{
		if (sum + el < sumLimit)
		{
			sum += el;
			return true;
		}
		return false;
	}
};


int main()
{
	const int maxSum{ 16 };
	const int size{ 10 };
	int arr1[size]{ 1,2,3,4,5,6,7,8,9,10 };
	int arr2[size]{};

	int* const arr1Begin{ arr1 };
	int* const arr1End{ arr1 + size };

	int* const arr2Begin{ arr2 };
	int* const arr2End{ arr2 + size };

	int* arr2NewEnd{};

	std::cout << "Original arr1:\n";
	print(arr1, arr1 + size);
	std::cout << "Original arr2:\n";
	print(arr2, arr2 + size);
	std::cout << '\n';

	std::cout << "arr2 copy of arr1 with elements sum limited to " << maxSum << ":\n";
	arr2NewEnd = arr2Begin + copy_if(arr1Begin, arr1End, arr2Begin, arr2End, SumLimit{ maxSum });
	print(arr2, arr2NewEnd);
	std::cout << '\n';

	return 0;
}