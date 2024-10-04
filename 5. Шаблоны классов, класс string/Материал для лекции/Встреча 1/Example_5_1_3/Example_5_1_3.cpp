#include <iostream>
#include <string>

template <class T>
void getValue(std::string prompt, T& value)
{
	cout << prompt;
	cin >> value;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Error... try again" << endl;
		cout << prompt;
		cin >> value;
	}
	string endLine;
	getline(cin, endLine);
}

int main()
{
	int number;
	getValue("Enter number: ", number);

	std::string name;
	getValue("Enter name: ", name);
}