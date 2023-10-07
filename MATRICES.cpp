#include"bscs22048_Matrices.h"
#include<iostream>
Matrix::Matrix()
{
    this->rows=0;this->cols=0;this->Vs=nullptr;
}
Matrix::Matrix(int R, int C)
{
    this->rows=R;this->cols=C;
    this->Vs=new float*[rows];
    for(int i=0;i<this->rows;i++)
    {
        this->Vs[i]=new float[cols];
    }
}
void Matrix::DeleteMatrix()
{
    for(int i=0;i<this->rows;i++)
    {
        delete []this->Vs[i];
    }
    delete[]this->Vs;
    this->rows=0;
    this->cols=0;
}
void Matrix::Allocate2D(int R, int C)
{
    this->rows=R;this->cols=C;
    this->Vs=new float*[this->rows];
    for(int i=0;i<this->rows;i++)
    {
        this->Vs[i]=new float[cols]{};
    }
}
void Matrix::LoadMatrix(ifstream& Rdr)
{
    this->Allocate2D(this->rows,this->cols);
    for(int i=0;i<this->rows;i++)
    {
        for(int j=0;j<this->cols;j++)
        {
            Rdr>>this->Vs[i][j];
        }
    }
}
Matrix::Matrix(ifstream& Rdr)
{
    
    Rdr>>this->rows;
    Rdr>>this->cols;
    this->LoadMatrix(Rdr);
}
void Matrix::PrintMatrix(const char* msg)const
{
    cout<<msg<<":";
    for(int i=0;i<this->rows;i++)
    {
        for(int j=0;j<this->cols;j++)
        {
            cout<<this->Vs[i][j]<<" ";
        }
        cout<<'\n';
    }
}
Matrix::Matrix(const Matrix& M)
{
    this->rows=M.rows;
    this->cols=M.cols;
    this->Allocate2D(this->rows,this->cols);
    for(int i=0;i<this->rows;i++)
    {
        for(int j=0;j<this->cols;j++)
        {
            this->Vs[i][j]=M.Vs[i][j];
        }
    }
}
Matrix Matrix::operator=(const Matrix& M)
{
    this->DeleteMatrix();
    this->rows=M.rows;
    this->cols=M.cols;
    this->Allocate2D(this->rows,this->cols);
    for(int i=0;i<this->rows;i++)
    {
        for(int j=0;j<this->cols;j++)
        {
            this->Vs[i][j]=M.Vs[i][j];
        }
    }
    return M;
}
Matrix Matrix::operator+(const Matrix& M)const
{
    Matrix sum;
    if(!(this->rows==M.rows&&this->cols==M.cols))
        return sum;
    sum.Allocate2D(M.rows,M.cols);
     for(int i=0;i<sum.rows;i++)
    {
        for(int j=0;j<sum.cols;j++)
        {
            sum.Vs[i][j]=this->Vs[i][j]+M.Vs[i][j];
        }
    }
    return sum;
}
void Matrix::operator+=(const Matrix& M)
{
    *this=(*this+M);
}
Matrix Matrix::operator-(const Matrix& M)const
{
    Matrix sub;
    if(!(this->rows==M.rows&&this->cols==M.cols))
        return sub;
    sub.Allocate2D(M.rows,M.cols);
     for(int i=0;i<sub.rows;i++)
    {
        for(int j=0;j<sub.cols;j++)
        {
            sub.Vs[i][j]=this->Vs[i][j]-M.Vs[i][j];
        }
    }
    return sub;
}
void Matrix::operator -=(const Matrix& M)
{
    *this=(*this-M);
}
Matrix Matrix::operator-(const int &s)const
{
    Matrix sub;
    sub.Allocate2D(this->rows,this->cols);
     for(int i=0;i<sub.rows;i++)
    {
        for(int j=0;j<sub.cols;j++)
        {
            sub.Vs[i][j]=this->Vs[i][j]-s;
        }
    }
    return sub;
}
Matrix Matrix::operator /(const float &s)const
{
    Matrix divi;
    divi.Allocate2D(this->rows,this->cols);
    for(int i=0;i<divi.rows;i++)
    {
        for(int j=0;j<divi.cols;j++)
        {
            divi.Vs[i][j]=this->Vs[i][j]/s;
        }
    }
    return divi;
}
Matrix Matrix::operator*(const int &s)const
{
    Matrix pro;
    pro.Allocate2D(this->rows,this->cols);
    for(int i=0;i<pro.rows;i++)
    {
        for(int j=0;j<pro.cols;j++)
        {
            pro.Vs[i][j]=this->Vs[i][j]*s;
        }
    }
    return pro;
}
Matrix Matrix::operator +(const int &s)const
{
    Matrix sum;
    sum.Allocate2D(this->rows,this->cols);
    for(int i=0;i<sum.rows;i++)
    {
        for(int j=0;j<sum.cols;j++)
        {
            sum.Vs[i][j]=this->Vs[i][j]+s;
        }
    }
    return sum;
}
Matrix Matrix::operator -()const
{
    Matrix res;
    res.Allocate2D(this->rows,this->cols);
    for(int i=0;i<res.rows;i++)
    {
        for(int j=0;j<res.cols;j++)
        {
            res.Vs[i][j]=-(this->Vs[i][j]);
        }
    }
    return res;
}
bool Matrix::operator==(const Matrix& M)const
{
    if(!(this->rows==M.rows&&this->cols==M.cols))
        return false;
    for(int i=0;i<this->rows;i++)
    {
        for(int j=0;j<this->cols;j++)
        {
            if(this->Vs[i][j]!=M.Vs[i][j])
                return false;
        }
    }
    return true;
}
Matrix Matrix::operator!()const
{
    Matrix res;
    res.Allocate2D(this->cols,this->rows);
    for(int i=0;i<this->rows;i++)
    {
        for(int j=0;j<this->cols;j++)
        {
            res.Vs[j][i]=this->Vs[i][j];
        }
    }
    return res;
}
Matrix Matrix::operator*(const Matrix &M)const
{
    Matrix res;
    if(this->cols!=M.rows)  
        return res;
    res.Allocate2D(this->rows,M.cols);
    for(int i=0;i<this->rows;i++)
    {
        for(int j=0;j<M.cols;j++)
        {
            float sum=0;
            for(int k=0;k<this->cols;k++)
            {
                sum+=(this->Vs[i][k]*M.Vs[k][j]);
            }
            res.Vs[i][j]=sum;
        }
    }
    return res;
    
}
const Matrix Matrix::operator++(int)
{
    Matrix temp=*this;
    *this=*this+1;
    return temp;
}
const Matrix Matrix::operator--(int)
{
    Matrix temp=*this;
    *this=*this-1;
    return temp;
}
Matrix  Matrix::RotateCW()
{
    Matrix res;
    res.Allocate2D(this->cols,this->rows);
    for(int i=0;i<this->rows;i++)
    {
        for(int j=0;j<this->cols;j++)
        {
            res.Vs[j][this->rows-i-1]=this->Vs[i][j];
        }
    }
    return res;
}
Matrix Matrix::RotateCWMult(int multiple)
{
    Matrix res=*this;
    for(int i=0;i<multiple;i++)
    {
        res=res.RotateCW();
    }
    return res;
}
Matrix  Matrix::RotateACW()
{
    Matrix res;
    res.Allocate2D(this->cols,this->rows);
    for(int i=0;i<this->rows;i++)
    {
        for(int j=0;j<this->cols;j++)
        {
            res.Vs[this->cols-j-1][i]=this->Vs[i][j];
        }
    }
    return res;
}
Matrix Matrix::RotateACWMult(int multiple)
{
    Matrix res=*this;
    for(int i=0;i<multiple;i++)
    {
        res=res.RotateACW();
    }
    return res;
}
Matrix Matrix::operator/(const Matrix &M)const
{
    return (*this)*(~M);
}
void Matrix::operator/=(const Matrix &M)
{
    *this=*this/M;
}
Matrix Matrix::multiply_row(const int & row,const float & num)
{
    Matrix temp=*this;
    for(int i=0;i<this->rows;i++)
    {
        temp.Vs[row][i]*=num;
    }
    return temp;
}
Matrix Matrix::divide_row(const int & row,const float & num)
{
    Matrix temp=*this;
    for(int i=0;i<this->rows;i++)
    {
        temp.Vs[row][i]/=num;
    }
    return temp;
}
Matrix Matrix::sub_two_rows(const int & a,const int & b)
{
    Matrix temp=*this;
    for(int i=0;i<this->cols;i++)
    {
        temp.Vs[a][i]-=temp.Vs[b][i];
    }
    return temp;
}
Matrix Matrix::operator~()const
{
    Matrix inverse;
    inverse.Allocate2D(this->rows,this->cols);
    for(int i=0;i<inverse.rows;i++)   
        inverse.Vs[i][i]=1;
    Matrix Rechelon=*this;
    for(int c=0;c<Rechelon.cols;c++)
    {
        if(Rechelon.Vs[c][c]!=0)
            inverse=inverse.divide_row(c,Rechelon.Vs[c][c]);
        else
        {
            inverse.DeleteMatrix();
            return inverse;
        }
        Rechelon=Rechelon.divide_row(c,Rechelon.Vs[c][c]);
        for(int r=0;r<Rechelon.rows;r++)
        {
            if(r!=c && Rechelon.Vs[r][c]!=0)
            {
                float num=Rechelon.Vs[r][c];
                Rechelon=Rechelon.multiply_row(c,num);
                inverse=inverse.multiply_row(c,num);
                //..............
                Rechelon=Rechelon.sub_two_rows(r,c);
                inverse=inverse.sub_two_rows(r,c);
                //..............
                Rechelon=Rechelon.divide_row(c,num);
                inverse=inverse.divide_row(c,num);
                
            }
                
        }    
    }
    
    return inverse;
}
