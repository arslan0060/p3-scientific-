//
//  compare.cpp
//  project3
//
//  Created by Arslan Memon on 10/19/15.
//  Copyright (c) 2015 Arslan. All rights reserved.
//

#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "matrix.hpp"
#include <chrono>// time library
using namespace std;
double Lagrange(Matrix& x, Matrix& y, double z);
Matrix Newton_coefficients(Matrix& x, Matrix& y);
double Newton_evaluate(Matrix& x, Matrix& c, double z);

int main()
{
    //funtion cosh(x^2/3) using lamda notation
   
    auto f = [](const double x) -> double {
        return (cosh(x*x/3.0));
        
    };
    //array of n and m values for testing
    int n[4]={10,20,40,80};
    int m[4]={100,1000,10000,100000};
        for (int i=0;i<4;i++)
    {
        //initialize x and y based on n+1 evenly spaced nodes
        Matrix x=Linspace(-2,2,n[i]+1);
        Matrix y(n[i]+1);
        
        
        for (int j=0; j<n[i]+1; j++) {
            y(j)=f(x(j));
        }
        //test time it takes to evaluate coefficients of  n+1 nodes using Newton_coefficients
        std::chrono::time_point<std::chrono::system_clock> start, end;
        start=chrono::system_clock::now();
        start=chrono::system_clock::now();
        Matrix c=Newton_coefficients(x, y);
        end = chrono::system_clock::now();
        chrono::duration<double> elapsed_seconds=end-start;
        cout<<"Newton coefficient construction with "<<n[i]+1<<" nodes took "<< elapsed_seconds.count() <<" seconds."<<endl;
        for(int j=0;j<4;j++)
        {
            Matrix z=Linspace(-2, 2, m[j]+1);//set of m+1 evenly spaced values between -2 and 2 that are going to be evaluated using Newton and Lagrange interpolation
           
            //measure time taken for Newton evaluation and print results
            
            start=chrono::system_clock::now();
            for (int k=0; k<m[j]+1; k++) {
                Newton_evaluate(x, c, z(k));
            }
            end = chrono::system_clock::now();
            elapsed_seconds = end-start;
            cout<<"Newton evaluation using "<<n[i]+1<<" nodes and "<<m[j]+1<<" z values took "<< elapsed_seconds.count() <<" seconds."<<endl;

            
            //measure time taken for Lagrange evaluation and print results
            start=chrono::system_clock::now();
            for (int k=0; k<m[j]+1; k++) {
               Lagrange(x, y, z(k));
            }
            end = chrono::system_clock::now();
            elapsed_seconds = end-start;
            cout<<"Lagrange evaluation using "<<n[i]+1<<" nodes and "<<m[j]+1<<" z values took "<< elapsed_seconds.count() <<" seconds."<<endl;
            
            
            
            
        }
        cout<<endl;
    }

}