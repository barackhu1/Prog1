/*	1. Print the size of a char , a short , an int , a long , a float , a double , an int* ,
and a double* (use sizeof , not <limits> ).

	2. Print out the size as reported by sizeof of Matrix<int> a(10) , Matrix<int>
b(100) , Matrix<double> c(10) , Matrix<int,2> d(10,10) , Matrix<int,3>
e(10,10,10) .

	3. Print out the number of elements of each of the Matrix es from 2.
	
	4. Write a program that takes int s from cin and outputs the sqrt() of each
int , or “no square root” if sqrt(x) is illegal for some x (i.e., check your
sqrt() return values).
	
	5. Read ten floating-point values from input and put them into a Matrix-
<double> . Matrix has no push_back() so be careful to handle an attempt
to enter a wrong number of double s. Print out the Matrix .
	
	6. Compute a multiplication table for [0,n)*[0,m) and represent it as a 2D
Matrix . Take n and m from cin and print out the table nicely (assume that
m is small enough that the results fit on a line).
	
	7. Read ten complex<double> s from cin (yes, cin supports >> for complex )
and put them into a Matrix . Calculate and output the sum of the ten com-
plex numbers.
	
	8. Read six int s into a Matrix<int,2> m(2,3) and print them out.*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include <cerrno>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

int main()
try{
	//1.feladat
	cout << "Size of char: " << sizeof(char) << endl;
	cout << "Size of short: " << sizeof(short) << endl;
	cout << "Size of int: " << sizeof(int) << endl;
	cout << "Size of long: " << sizeof(long) << endl;
	cout << "Size of float: " << sizeof(float) << endl;
	cout << "Size of double: " << sizeof(double) << endl;
	cout << "Size of int*: " << sizeof(int*) << endl;
	cout << "Size of double: " << sizeof(double*) << endl;
	cout << endl;
	//2.feladat
	Matrix<int> a(10);
	Matrix<int> b(100);
	Matrix<double> c(10);
	Matrix<int,2> d(10,10);
	Matrix<int,3> e(10,10,10);
	cout << "Size of a: " << sizeof(a) << endl;
	cout << "Size of b: " << sizeof(b) << endl;
	cout << "Size of c: " << sizeof(c) << endl;
	cout << "Size of d: " << sizeof(d) << endl;
	cout << "Size of e: " << sizeof(e) << endl;
	cout << endl;
	//3.feladat
	cout << "Number of elements in a matrix: " << a.size()<< endl;
	cout << "Number of elements in b matrix: " << b.size()<< endl;
	cout << "Number of elements in c matrix: " << c.size()<< endl;
	cout << "Number of elements in d matrix: " << d.size()<< endl;
	cout << "Number of elements in e matrix: " << e.size()<< endl;
	cout << endl;
	//4.feladat
	int i;
	while(cin >> i){
		double d = sqrt(i);
		if (i < 0){
			cout << "no square root" << endl;
		}
		else{
			cout << "sqrt(" << i << ") = " << d << endl;	
		}
	}
	//5.feladat
	cin.clear();
    cin.ignore();
	cout << endl;
	cout << "Enter 10 floats: ";
	Matrix<double> m2(10);
	double d2;
	for (int i = 0; i < m2.size(); ++i)
	{
		cin >> d2;
		m2[i] = d2;
	}
	cout << "Matrix:\n" << m2 << endl;
	cout << endl;
	//6.feladat
	int n,m;
	cout << "n value of matrix: ";
	cin >> n;
	cout << "m value of matrix: ";
	cin >> m;
	cout << endl;
	Matrix<int, 2> mult (n,m);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			mult(i,j)=(i+1)*(j+1);
			cout << mult(i,j) << '\t';
		}
		cout << endl;
	}
	cout << endl;
	//7.feladat
	Matrix<complex<double>> mc(10);
	cout << "Enter 10 complex numbers (Re, Im): ";
	complex<double> comp;
	for (int i = 0; i < 10; ++i)
	{
		cin >> comp;
		if (!cin) throw runtime_error("Problem reading complex number!");
		mc[i] = comp;
	}
	complex<double> sum;
	for (int i = 0; i < mc.size(); ++i)
	{
		sum += mc[i];
	}
	cout << "sum: " << sum << endl;
	cout << endl;
	//8.feladat
	Matrix<int, 2> m3 (2,3);
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> m3(i,j);
		}
	}

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << m3(i,j) << '\t';
		}
		cout << endl;
	}

} catch(exception& e) {
	cerr << e.what() << '\n';
	return 1;
} catch(...) {
	cerr << "Unknown exception!" << '\n';
	return 2;
}