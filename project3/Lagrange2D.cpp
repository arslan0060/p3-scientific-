//
//  Lagrange2D.cpp
//  project3
//
//  Created by Arslan Memon on 10/22/15.
//  Copyright (c) 2015 Arslan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "matrix.hpp"

using namespace std;
double Lagrange_basis(Matrix& x, int i, double z);
double Lagrange2D(Matrix& x, Matrix& y, Matrix& f, double a, double b)
{
    double lagAnswer=0.0;

    for(int j=0;j<y.Size();j++)//loop to evaluate f(a,b). reason for using j first is to efficiently access matrix how it's stored
    {
        
        for (int i=0; i<x.Size(); i++)
        {
            lagAnswer+=f(i,j)*Lagrange_basis(x,i, a)*Lagrange_basis(y, j, b);//multiplying f(i,j) by the lagrange basis for b with nodes y* lagrange basis for a with nodes x to get an approximate of f(a,b) using lagrange interpolation
         }
    }
    return lagAnswer;

}