#include <iostream>
#include <assert.h>
#include <Matrix.h>

Matrix::Matrix(int rows, int cols) : m_rows(rows), m_cols(cols){
	m_array.assign(rows, std::vector<int>(cols, 0));
}

Matrix::Matrix(const Matrix& b) : Matrix(b.m_rows, b.m_cols){
	m_array = b.m_array;
}

Matrix::~Matrix(){}

int Matrix::Rows() const {
	return m_rows;
}

int Matrix::Cols() const {
	return m_cols;
}

void Matrix::resize(int rows, int cols){
	m_rows = rows;
	m_cols = cols;
	m_array.resize(m_rows);
	for(auto& row: m_array)
		row.resize(m_cols);
}

Matrix& Matrix::Add(const Matrix& b){
	assert(m_rows==b.m_rows && m_cols==b.m_cols);
	for(int r=0; r<m_rows; r++)
		for(int c=0; c<m_cols; c++)
			m_array.at(r).at(c) += b.m_array.at(r).at(c);
	return *this;
}

Matrix& Matrix::Sub(const Matrix& b){
	assert(m_rows==b.m_rows && m_cols==b.m_cols);
	for(int r=0; r<m_rows; r++)
		for(int c=0; c<m_cols; c++)
			m_array.at(r).at(c) -= b.m_array.at(r).at(c);
	return *this;
}

Matrix& Matrix::Mul(const Matrix& b){
	assert(m_cols==b.m_rows);
	Matrix* a = new Matrix(*this);
	resize(a->m_rows, b.m_cols);
	for(int r=0; r<a->m_rows; r++)
		for(int c=0; c<b.m_cols; c++){
			m_array.at(r).at(c) = 0;
			for(int k=0; k<b.m_rows; k++)
				m_array.at(r).at(c) += a->m_array.at(r).at(k) * b.m_array.at(k).at(c);
		}
	delete a;
	return *this;
}

bool Matrix::Eq(const Matrix& b){
	bool result = m_rows==b.m_rows && m_cols==b.m_cols;
	if(result)
		for(int r=0; r<m_rows; r++)
			for(int c=0; c<m_cols; c++)
				if(m_array.at(r).at(c) != b.m_array.at(r).at(c))return false;
	return result;
}

void Matrix::Tran(){
	Matrix* t = new Matrix(*this);
	resize(t->m_cols, t->m_rows);
	for(int r=0; r<m_rows; r++)
		for(int c=0; c<m_cols; c++)
			m_array.at(r).at(c) = t->m_array.at(c).at(r);
	delete t;
}

int Matrix::Min(){
	int min = m_array.at(0).at(0);
	for(auto& row: m_array)
		for(auto& el: row)
			if(el<min)min=el;
	return min;
}

void Matrix::Show(){
	for(int r=0; r<m_rows; r++){
		for(int c=0; c<m_cols; c++)
			std::cout << "\t" << m_array.at(r).at(c);
		std::cout << std::endl;
	}
};

int& Matrix::operator()(int r, int c){
	assert(r>=0 && r<m_rows && c>=0 && c<=m_cols);
	return m_array.at(r).at(c);
}

Matrix& Matrix::operator=(const Matrix& b){
	assert(m_rows==b.m_rows && m_cols==b.m_cols);
	m_array = b.m_array;
	return *this;
}

Matrix& Matrix::operator+(const Matrix& b){
	assert(m_rows==b.m_rows && m_cols==b.m_cols);
	Matrix* result = new Matrix(m_rows, m_cols);
	for(int r=0; r<m_rows; r++)
		for(int c=0; c<m_cols; c++)
			result->m_array.at(r).at(c) = m_array.at(r).at(c) + b.m_array.at(r).at(c);
	return *result;
}

Matrix& Matrix::operator+=(const Matrix& b){
	assert(m_rows==b.m_rows && m_cols==b.m_cols);
	for(int r=0; r<m_rows; r++)
		for(int c=0; c<m_cols; c++)
			m_array.at(r).at(c) += b.m_array.at(r).at(c);
	return *this;
}

Matrix& Matrix::operator-(const Matrix& b){
	assert(m_rows==b.m_rows && m_cols==b.m_cols);
	Matrix* result = new Matrix(m_rows, m_cols);
	for(int r=0; r<m_rows; r++)
		for(int c=0; c<m_cols; c++)
			result->m_array.at(r).at(c) = m_array.at(r).at(c) - b.m_array.at(r).at(c);
	return *result;
}

Matrix& Matrix::operator-=(const Matrix& b){
	assert(m_rows==b.m_rows && m_cols==b.m_cols);
	for(int r=0; r<m_rows; r++)
		for(int c=0; c<m_cols; c++)
			m_array.at(r).at(c) -= b.m_array.at(r).at(c);
	return *this;
}

Matrix& Matrix::operator*(const Matrix& b){
	assert(m_cols==b.m_rows);
	Matrix* result = new Matrix(m_rows, b.m_cols);
	for(int r=0; r<m_rows; r++)
		for(int c=0; c<b.m_cols; c++)
			for(int k=0; k<m_cols; k++)
				result->m_array.at(r).at(c) += m_array.at(r).at(k)*b.m_array.at(k).at(c);
	return *result;
}

bool Matrix::operator==(const Matrix& b){
	bool result = m_rows==b.m_rows && m_cols==b.m_cols;
	if(result)
		for(int r=0; r<m_rows; r++)
			for(int c=0; c<m_cols; c++)
				if(m_array.at(r).at(c)!=b.m_array.at(r).at(c))return false;
	return result;
}
