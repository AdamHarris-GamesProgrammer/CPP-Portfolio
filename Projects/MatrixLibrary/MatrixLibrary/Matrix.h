#pragma once

#ifndef __Matrix_H
#define __Matrix_H

#include <vector>

template<typename T> class Matrix
{
private:
	std::vector<std::vector<T>> mat;
	unsigned rows;
	unsigned cols;

public:
	Matrix(unsigned rows, unsigned cols, const T& initial);
	Matrix(const Matrix<T>& rhs);
	virtual ~Matrix();

	//Operator overloading
	Matrix<T>& operator=(const Matrix<T>& rhs);

	Matrix<T> operator+(const Matrix<T>& rhs);
	Matrix<T>& operator+=(const Matrix<T>& rhs);
	Matrix<T> operator-(const Matrix<T>& rhs);
	Matrix<T>& operator-=(const Matrix<T>& rhs);
	Matrix<T> operator*(const Matrix<T>& rhs);
	Matrix<T>& operator*=(const Matrix<T>& rhs);

	//Transpose
	Matrix<T> Transpose();

	//Matrix/scalar operations
	Matrix<T> operator+(const T& rhs);
	Matrix<T> operator-(const T& rhs);
	Matrix<T> operator*(const T& rhs);
	Matrix<T> operator/(const T& rhs);

	//Matrix/Vector operations
	std::vector<T> operator*(const std::vector<T>& rhs);
	std::vector<T> DiagVec();

	//Access individual elements
	T& operator()(const unsigned& row, const unsigned& col);
	const T& operator()(const unsigned& row, const unsigned& col) const;

	//Access row and column sizes
	unsigned GetRows() const;
	unsigned GetCols() const;
};



#include "Matrix.cpp"

#endif __Matrix_H

