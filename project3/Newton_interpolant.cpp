//
//  Newton_interpolant.cpp
//  project3
//
//  Created by Arslan Memon on 10/15/15.
//  Copyright (c) 2015 Arslan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "matrix.hpp"

using namespace std;
Matrix Newton_coefficients(Matrix& x, Matrix& y)// find coefficients for interpolation
{
    if(x.Size()!=y.Size())//not possible to find coefficients if there isn't a y for every x
    {
        return Matrix(0,0);
    }
    Matrix coeff(x.Size());//coefficiennt matrix size  is same as the number of nodes
    
    for (int i=0;i<x.Size();i++)//initialize coeff matrix with y values
    {
        coeff(i)=y(i);
    }
    for (int j=1;j<x.Size(); j++)// the first coefficient is the y value and then forward substitution is used to find other coefficients
    {
        for(int i=x.Size()-1;i>=j;i--)
        {
            coeff(i)=(coeff(i)-coeff(i-1))/(x(i)-x(i-j));
        }
    }
    
    return coeff;

}
double Newton_evaluate(Matrix& x, Matrix& c, double z)//eval z using Newton interpolation
{
    double tmp=c(c.Size()-1);//set tmp to last coefficient in the matrix
    for (int i=c.Size()-1;i>=0;i--)//use  nested multiplication to evaluate at z
    {
        tmp=(tmp*(z-x(i)))+c(i);
    }
    return tmp;
}