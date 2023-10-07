#pragma once
#include<iostream>
using namespace std;
#include<fstream>
class Matrix
{
	float** Vs;
	int rows;
	int cols;
	Matrix multiply_row(const int &,const float &);
	Matrix divide_row(const int &,const float &);
	Matrix sub_two_rows(const int &,const int &);
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
	Matrix operator-(const int &s)const;
	Matrix operator /(const float &s)const;
	Matrix operator*(const int &s)const;
	Matrix operator +(const int &s)const;
	Matrix operator -()const;
	bool operator==(const Matrix& M)const;
	Matrix operator!()const;
	Matrix operator*(const Matrix &M)const;
	Matrix operator~()const;
	Matrix operator/(const Matrix &M)const;
	void operator/=(const Matrix &M);
	const Matrix operator--(int);
	const Matrix operator++(int);
	Matrix RotateCW();
	Matrix RotateCWMult(int multiple);
	Matrix RotateACW();
	Matrix RotateACWMult(int multiple);
};
