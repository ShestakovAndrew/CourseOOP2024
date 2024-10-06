#pragma once
#include "matrix.h"

template <class T>
class NumberMatrix : public Matrix<T>
{
public:
	NumberMatrix(int height, int width) : Matrix<T>(height, width)
	{}

	NumberMatrix(int size) : NumberMatrix(size)
	{}

	void setRand(int max = 100, int min = 0)
	{
		for (int j = 0; j < this->height; j++)
		{
			for (int i = 0; i < this->width; i++)
			{
				this->m[j][i] = (T)(min + rand() % (max - min + 1));
			}
		}
	}

	friend NumberMatrix<T> operator+(const NumberMatrix<T>& m1,
		const NumberMatrix<T>& m2)
	{
		if (m1.height != m2.height ||
			m1.width != m2.width)
		{
			stopProgram("Matrix sizes do not match!");
		}

		NumberMatrix<T> mRes(m1.height, m1.width);
		for (int j = 0; j < mRes.height; j++)
		{
			for (int i = 0; i < mRes.width; i++)
			{
				mRes.m[j][i] = m1.m[j][i] + m2.m[j][i];
			}
		}
		return mRes;
	}

	friend NumberMatrix<T> operator-(const NumberMatrix<T>& m1,
		const NumberMatrix<T>& m2)
	{
		if (m1.height != m2.height ||
			m1.width != m2.width)
		{
			if (m1.height != m2.height ||
				m1.width != m2.width)
			{
				stopProgram("Matrix sizes do not match!");
			}
		}

		NumberMatrix<T> mRes(m1.height, m1.width);
		for (int j = 0; j < mRes.height; j++)
		{
			for (int i = 0; i < mRes.width; i++)
			{
				mRes.m[j][i] = m1.m[j][i] - m2.m[j][i];
			}
		}
		return mRes;
	}

	friend std::ostream& operator<<(std::ostream& output,
		const NumberMatrix& matrix)
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

