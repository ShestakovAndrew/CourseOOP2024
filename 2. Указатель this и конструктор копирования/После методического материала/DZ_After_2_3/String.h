#pragma once
#include <iostream>
#include <cstring>

class String
{
private:
	size_t m_size;
	char* m_string;

public:
	String(const char* str);

	String(size_t length);

	String(const String& other);

	void Display() const;

	void SetString(const char* str);

	size_t GetSize() const;

	~String();
};

