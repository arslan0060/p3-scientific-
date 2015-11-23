//
//  Runge_uniform.cpp
//  project3
//
//  Created by Arslan Memon on 10/24/15.
//  Copyright (c) 2015 Arslan. All rights reserved.
//
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "matrix.hpp"
using namespace std;
double Lagrange2D(Matrix& x, Matrix& y, Matrix& f, double a, double b);
int main()
{
    //runge fuction
    auto funct = [](const double x,const double y) -> double {
        return (1.0/(1+x*x+y*y));
    };
    //set m and n to 6
    int n=6;
    int m=6;
    //set x to m+1 evenly spaced nodes from -4 to 4 and y to n+1 evenly spaced nodes between -4 and 4
    Matrix x=Linspace(-4.0, 4.0, m+1, 1);
    Matrix y=Linspace(-4.0, 4.0, n+1, 1);
    Matrix f(m+1,n+1);//2d matrix f m+1 by n+1
    for(int j=0;j<=n;j++)// use runge function to initialize f
    {
        for (int i=0; i<=m;i++) {
            f(i,j)=funct(x(i),y(j));
        }
    }
    
    Matrix a=Linspace(-4.0, 4.0, 201, 1);//a is a matrix of 201 evenly spaced nodes between -4 and 4
    Matrix b=Linspace(-4.0, 4.0, 101, 1);//b is a matrix of 101 evenly spaced nodes between -4 and 4
    a.Write("avals.txt");//store a and b
    b.Write("bvals.txt");
    Matrix p6(201,101);
    //evaluate and store f(a,b) using Lagrange2D interpolation and write to disk
    for(int j=0;j<101;j++)
    {
        for (int i=0; i<201;i++) {
            p6(i,j)=Lagrange2D(x, y, f, a(i), b(j));
        }
    }
    p6.Write("p6_uni.txt");
    //same as above except wth m=n=24
    m=24;
    n=24;
    x=Linspace(-4.0, 4.0, m+1, 1);
    y=Linspace(-4.0, 4.0, n+1, 1);
    f=Matrix(m+1,n+1);
    for(int j=0;j<=n;j++)
    {
        for (int i=0; i<=m;i++) {
            f(i,j)=funct(x(i),y(j));
        }
    }
    
    Matrix p24(201,101);
    for(int j=0;j<101;j++)
    {
        for (int i=0; i<201;i++) {
            p24(i,j)=Lagrange2D(x, y, f, a(i), b(j));
        }
    }
    p24.Write("p24_uni.txt");
    Matrix Runge(201,101);
    for(int j=0;j<101;j++)
    {
        for (int i=0; i<201;i++) {
            Runge(i,j)=funct(a(i),b(j));
        }
    }
    Runge.Write("Runge.txt");
}
