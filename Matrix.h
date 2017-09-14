/* 
 * Matrix.h
 * © 2017 Sergey Roganov <sergey@roganof.ru>
 * GNU/GPL v.3+
 */

#include<vector>

class Matrix
{
	std::vector<std::vector<int> > m_array;
	int m_rows, m_cols;
	void resize(int rows, int cols);
public:
	Matrix(int rows, int cols);
	Matrix(const Matrix& b);
	~Matrix();
	int Rows() const;
	int Cols() const;
	Matrix& Add(const Matrix& b);
	Matrix& Sub(const Matrix& b);
	Matrix& Mul(const Matrix& b);
	bool Eq(const Matrix& b);
	void Tran();
	int Min();
	void Show();
	int& operator()(int r, int c);
	Matrix& operator=(const Matrix& b);
	Matrix& operator+(const Matrix& b);
	Matrix& operator+=(const Matrix& b);
	Matrix& operator-(const Matrix& b);
	Matrix& operator-=(const Matrix& b);
	Matrix& operator*(const Matrix& b);
	bool operator==(const Matrix& b);
};
