//
//  test.cpp
//  project3
//
//  Created by Arslan Memon on 10/15/15.
//  Copyright (c) 2015 Arslan. All rights reserved.
//

#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "matrix.hpp"
using namespace std;
Matrix Newton_coefficients(Matrix& x, Matrix& y);
double Newton_evaluate(Matrix& x, Matrix& c, double z);
//same thing as test_lagrange, that's why the comments are the same. the only difference is that the points are evaluated using Newton interpolation
int main()
{
    auto f = [](const double x) -> double {
        return (cosh(2.0*x*x));
    };
    
    // array of n values for testing
    vector<size_t> nvals = {10, 20};
    
    // loop over tests
    for (size_t k=0; k<nvals.size(); k++) {
        
        // set n, output test information
        int n = nvals[k];
        cout << endl << "interpolants and errors using " << n+1 << " nodes:\n";
        
        // set arrays of nodes and data values
        Matrix x = Linspace(0.0, 1.0, n+1, 1);  // set column vector of nodes
        Matrix y(n+1);                          // initialize data
        for (int i=0; i<=n; i++)                // fill data
            y(i) = f(x(i));
        
        // set evaluation points z as midpoints between nodes
        double dx = 1.0/n;                   // set node spacing
        Matrix z = Linspace(dx/2.0, 1.0-dx/2.0, n, 1);
        Matrix c=Newton_coefficients(x, y);
        Matrix p(n);
        // evaluate the Newton polynomial at the points z, storing in p

        for (int i=0; i<n; i++)
        {
            p(i) = Newton_evaluate(x, c, z(i));
        }
        // output errors at each point
        cout << "      z        f(z)               p(z)             err\n";
        for (int i=0; i<n; i++)
            printf("   %6.3f   %16.13f   %16.13f   %7.2g\n",
                   z(i), f(z(i)), p(i), fabs(f(z(i))-p(i)));
    }
    }
  


