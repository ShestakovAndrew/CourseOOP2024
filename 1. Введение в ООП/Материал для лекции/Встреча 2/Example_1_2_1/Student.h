#pragma once

class Student
{
private:
	// ���
	char name[21];
	// ������
	int marks[3];
public:
	// ������ �������� ������ ������
	const char* getName()
	{
		return name;
	}

	int getMark(int index)
	{
		return marks[index];
	}
	// ������ �������� ������ ������
	void setName(const char* studentName);
	void setMark(int mark, int index);
	// ���������� �������� �����
	double getAver();
};