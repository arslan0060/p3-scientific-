//
//  Runge_Chebyshev.cpp
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
//same as Runge_uniform, except using Chebyshev nodes instead of uniform nodes
int main()
{
    
    auto funct = [](const double x,const double y) -> double {
        return (1.0/(1+x*x+y*y));
    };
    int n=6;
    int m=6;
    Matrix x(m+1);
    Matrix y(n+1);
    for (int i=0;i<=n;i++)//Chebyshev nodes formula
    {
        x(i)=(4*cos(((2*i+1)*M_PI)/(2*m+2)));
        y(i)=(4*cos(((2*i+1)*M_PI)/(2*m+2)));
    }
    Matrix f(m+1,n+1);
    for(int j=0;j<=n;j++)
    {
        for (int i=0; i<=m;i++) {
            f(i,j)=funct(x(i),y(j));
        }
    }
    
    Matrix a=Linspace(-4, 4, 201);
    Matrix b=Linspace(-4, 4, 101);
    Matrix p6(201,101);
    for(int j=0;j<101;j++)
    {
        for (int i=0; i<201;i++) {
            p6(i,j)=Lagrange2D(x, y, f, a(i), b(j));
        }
    }
    p6.Write("p6_Cheb.txt");
    m=24;
    n=24;
    x=Matrix(m+1);
    y=Matrix(n+1);
    f=Matrix(m+1,n+1);
    for (int i=0;i<=n;i++)
    {
        x(i)=(4*cos(((2*i+1)*M_PI)/(2*m+2)));
        y(i)=(4*cos(((2*i+1)*M_PI)/(2*m+2)));
    }

    for(int j=0;j<=n;j++)
    {
        for (int i=0; i<=n;i++) {
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
    p24.Write("p24_Cheb.txt");

}
