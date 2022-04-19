#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include <cerrno>
#include "source/Matrix.h"
#include "source/MatrixIO.h"

using namespace std;
using namespace Numeric_lib;


int main(){
    try {
        cout << "sizeof:\n";
        cout << "char\t" << sizeof(char) << "\n";
        cout << "short\t" << sizeof(short) << "\n";
        cout << "int\t" << sizeof(int) << "\n";
        cout << "long\t" << sizeof(long) << "\n";
        cout << "float\t" << sizeof(float) << "\n";
        cout << "double\t" << sizeof(double) << "\n";
        cout << "int*\t" << sizeof(int*) << "\n";
        cout << "double*\t" << sizeof(double*) << "\n";

        cout << "Matrix sizes:\n";
        Matrix<int> a(10);
        Matrix<int> b(100);
        Matrix<double> c(10);
        Matrix<int, 2> d(10, 10);
        Matrix<int, 3> e(10, 10, 10);

//1.:
        cout << "1D int, 10 elem\t\t" << sizeof(a) << '\n';
        cout << "1D int, 100 elem\t" << sizeof(b) << '\n';
        cout << "1D int, 10 elem\t\t" << sizeof(c) << '\n';
        cout << "2D int, 10x10 elem\t" << sizeof(d) << '\n';
        cout << "3D int, 10x10x10 elem\t" << sizeof(e) << '\n';

//2.:
        cout << "number of elements:\n";
        cout << "a:\t" << a.size() << '\n';
        cout << "b:\t" << b.size() << '\n';
        cout << "c:\t" << c.size() << '\n';
        cout << "d:\t" << d.size() << '\n';
        cout << "e:\t" << e.size() << '\n';


//4.:
        int i;
        cout << "\nEnter ints: ";
        while (cin >> i){
            errno = 0;
            double d = sqrt(i);
            if (errno == EDOM)
                cout << "no square root\n";
            else
                cout << "sqrt(" << i << ") = " << d << '\n';
        }

        cin.clear();
        cin.ignore();

//5.:        
        cout << "\nEnter 10 floats: ";
        Matrix<double> m(10);
        Matrix<int> n(10);
        double d2;
        for (int i=0; i < m.size(); ++i){
            cin>>d2;
            if(!cin) throw runtime_error("Error while reading from cin!");
            m[i] = d2;
            n[i] = d2;
        }
//6.:
        
        cout << "Matrix:\n" << m << '\n';
        cout << "Matrix:\n" << n << '\n';
        Matrix<int, 2> nm(m.size(), n.size());
        for (int i = 0; i < m.size(); ++i){
            for (int j = 0; j < m.size(); ++j){
                nm(i, j) = n(i) * m(j);
            }            
        }
//7.:
        Matrix<complex<double>> m4(10);

        cout << "\nEnter 10 complex double numbers (Re, Im): ";
        complex<double> comp;
        for(int i = 0; i < 10; ++i) {
            cin >> comp;
            if(!cin) throw runtime_error("Error while reading from cin!");
            m4[i] = comp;
        }
        complex<double> sum;
        for(int i = 0; i < m4.size(); ++i){
            sum += m4[i];
        }
        cout << "Sum: " << sum << '\n';
//8.:
        Matrix<int, 2> m8(2, 3);
        for(int i = 0; i < m8.dim1(); ++i){
            for(int j = 0; j < m8.dim2(); ++j){
                cin >> m8(i, j);
            }
        }
        cout << "Matrix m8: " << m8 << '\n';
        return 0;
    } catch (exception& e){
        cerr << e.what() << '\n';
        return 1;
    } catch (...){
        cerr << "Unknown exception";
        return 2;
    }
}