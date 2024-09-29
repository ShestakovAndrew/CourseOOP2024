#include <iostream>

class Counter
{
private:
	int cnt;

public:
	Counter(int start) : cnt{ start } {};
	Counter() : Counter(0) {};
	int operator()() { return cnt++; }
	void resetTo(int start) { cnt = start; }
};

int main()
{
	const int maxCnt{ 5 };

	Counter cnt1{};
	for (int i{ 0 }; i < maxCnt; ++i)
	{
		std::cout << cnt1() << ' ';
	}
	std::cout << '\n';

	cnt1.resetTo(10);

	for (int i{ 0 }; i < maxCnt; ++i)
	{
		std::cout << cnt1() << ' ';
	}
	std::cout << '\n';

	return 0;
}