/* 
 * ConsoleApplicationMatrix
 * © 2017 Sergey Roganov <sergey@roganof.ru>
 * GNU/GPL v.3+
 */

#include <iostream>
#include <Matrix.h>

void fillMatrix(Matrix& matrix){
	for(int r=0; r < matrix.Rows(); r++){
		for(int c=0; c < matrix.Cols(); c++){
			matrix(r, c) = matrix.Rows()*r+c;
		}
	}
}

int main(int argc, char **argv){
	Matrix a = Matrix(3, 5);
	Matrix b = Matrix(3, 5);
	fillMatrix(a);
	fillMatrix(b);
	
	using namespace std;
	
	cout << "a" << endl;
	a.Show();
	cout << "b" << endl;
	b.Show();
	
	cout << "a.Eq(b) ? " << a.Eq(b) << endl;
	
	cout << "a.Add(b)" << endl;
	a.Add(b);
	a.Show();
	
	cout << "a == b ? " << (a==b) << endl;
	
	cout << "a + b" << endl;
	(a+b).Show();
	
	cout << "a.Sub(b)" << endl;
	a.Sub(b);
	a.Show();
	
	cout << "a - b" << endl;
	(a-b).Show();
	
	b.Tran();
	cout << "b.Tran()" << endl;
	b.Show();
	cout << "a * b" << endl;
	(a*b).Show();
	b.Mul(a);
	cout << "b.Mul(a)" << endl;
	b.Show();
	cout << "b.Min() = " << b.Min() << endl;
	
	return 0;
}
