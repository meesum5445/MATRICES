#pragma once
#include<iostream>
using namespace std;
#include<fstream>
class Matrix
{
	int** Vs;
	int rows;
	int cols;
public:
	Matrix();
	Matrix(int R, int C);
	void DeleteMatrix();
	void Allocate2D(int R, int C);
	void LoadMatrix(ifstream& Rdr);
	Matrix(ifstream& Rdr);
	void PrintMatrix(const char* msg)const;
	Matrix(const Matrix& M);
	Matrix operator=(const Matrix& M);
	Matrix operator+(const Matrix& M)const;
	void operator+=(const Matrix& M);
	Matrix operator-(const Matrix& M)const;
	void operator -=(const Matrix& M);
	Matrix operator-(const int &s)const;//scalar subtraction
	Matrix operator /(const float &s)const;//scalar division
	Matrix operator*(const int &s)const;//scalar multiplication
	Matrix operator +(const int &s)const;//scalar addition
	Matrix operator -()const;//
	bool operator==(const Matrix& M)const;
	Matrix operator!()const;//transpose
	Matrix operator*(const Matrix &M)const;//this*M;
// 	Matrix operator~();//inverse of a 2 by 2 matrix
// 	Matrix operator/(Matrix M);//A/M=A inv B
// 	Matrix operator/=(Matrix M);
	const Matrix operator--(int);
	const Matrix operator++(int);
	Matrix RotateCW();
	Matrix RotateCWMult(int multiple);
	Matrix RotateACW();
	Matrix RotateACWMult(int multiple);
};