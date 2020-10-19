#include "Matrix.h"

template<typename T>
unsigned Matrix<T>::GetCols() const
{
	return cols;
}

template<typename T>
unsigned Matrix<T>::GetRows() const
{
	return rows;
}

template<typename T>
const T& Matrix<T>::operator()(const unsigned& row, const unsigned& col) const
{
	return mat.at(row).at(col);
}

template<typename T>
T& Matrix<T>::operator()(const unsigned& row, const unsigned& col)
{
	return mat.at(row).at(col);
}

template<typename T>
std::vector<T> Matrix<T>::DiagVec()
{
	std::vector<T> result;
	result.resize(rows);

	for (int i = 0; i < result.size(); i++) {
		result[i] = mat(i, i);
	}

	return result;
}

template<typename T>
std::vector<T> Matrix<T>::operator*(const std::vector<T>& rhs)
{

}

template<typename T>
Matrix<T> Matrix<T>::operator/(const T& rhs)
{
	Matrix result(rows, cols, 0.0);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			result(i, j) = mat(i, j) / rhs;
		}
	}

	return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const T& rhs)
{
	Matrix result(rows, cols, 0.0);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			result(i, j) = mat(i, j) * rhs;
		}
	}

	return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const T& rhs)
{
	Matrix result(rows, cols, 0.0);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			result(i, j) = mat(i, j) - rhs;
		}
	}

	return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const T& rhs)
{
	Matrix result(rows, cols, 0.0);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			result(i, j) = mat(i, j) + rhs;
		}
	}

	return result;
}

template<typename T>
Matrix<T> Matrix<T>::Transpose()
{

}

template<typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& rhs)
{

}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& rhs)
{

}

template<typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& rhs)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			mat(i, j) -= mat(i, j);
		}
	}

	return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& rhs)
{
	Matrix result(rows, cols, 0.0);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			result(i, j) = mat(i, j) - mat(i, j);
		}
	}

	return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& rhs)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			mat(i, j) += mat(i, j);
		}
	}

	return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs)
{
	Matrix result(rows, cols, 0.0);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			result(i, j) = mat(i, j) + mat(i, j);
		}
	}

	return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs)
{
	if (&rhs == this) return *this;

	mat = rhs.mat;

	return *this;
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& rhs)
{
	mat = rhs.mat;
}

template<typename T>
Matrix<T>::Matrix(unsigned rows, unsigned cols, const T& initial) : rows(rows), cols(cols) 
{
	mat.resize(rows);
}