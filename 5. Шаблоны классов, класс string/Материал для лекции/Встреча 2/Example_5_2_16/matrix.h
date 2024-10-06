#pragma once
#include <iostream>

void stopProgram(std::string message);

template <class T>
class Matrix
{
protected:
	int height;
	int width;
	T** m;

private:
	bool allocate(int height, int width)
	{
		if (height <= 0 && width <= 0)
		{
			return false;
		}

		this->height = height;
		this->width = width;
		m = new T * [height];
		for (int j = 0; j < height; j++)
		{
			m[j] = new T[width];
			for (int i = 0; i < width; i++)
			{
				m[j][i] = T();
			}
		}
		return true;
	}

	void clear()
	{
		if (m != nullptr)
		{
			for (int j = 0; j < height; j++)
			{
				delete[] m[j];
			}
			delete[] m;
		}
		m = nullptr;
	}

	void copyTo(T** from)
	{
		for (int j = 0; j < height; j++)
		{
			for (int i = 0; i < width; i++)
			{
				m[j][i] = from[j][i];
			}
		}
	}

public:
	Matrix(int height, int width)
	{
		if (height <= 0 || width <= 0)
		{
			stopProgram("Wrong sizes!");
		}

		if (!allocate(height, width))
		{
			stopProgram("Wrong sizes!");
		}
	}

	Matrix(int size) : Matrix(size, size)
	{}

	Matrix()
	{
		height = width = 0;
		m = nullptr;
	}

	Matrix(const Matrix& matrix)
	{
		clear();
		allocate(matrix.height, matrix.width);
		copyTo(matrix.m);
	}

	~Matrix()
	{
		clear();
	}

	auto& operator()(int j, int i)
	{
		if (j < 0 || j >= height
			|| i < 0 || i >= width)
		{
			stopProgram("Matrix index error!");
		}

		return m[j][i];
	}

	Matrix<T>& operator=(const Matrix<T>& matrix)
	{
		if (&matrix == this)
		{
			return *this;
		}

		clear();
		allocate(matrix.height, matrix.width);
		copyTo(matrix.m);
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& output,
		const Matrix& matrix)
	{
		if (matrix.m == nullptr)
		{
			output << "Empty matrix" << std::endl;
		}
		for (int j = 0; j < matrix.height; j++)
		{
			for (int i = 0; i < matrix.width; i++)
			{
				output << " " << matrix.m[j][i];
			}
			output << std::endl;
		}
		return output;
	}
};

