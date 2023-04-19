#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

double functionb(double x){
    if (x == 0){
        return 0;
    }
    else {
    return x * sin(1.0/x);
    }
}
double functiona(double x){
    if (x == 0){
        return 0;
    }
    else {
    return exp(-x)/x;
    }
}

double Trapez(double a, double b, int N, double (*function)(double)){
    double h = (b-a)/N;
    double value = h/2.0 * ((*function)(a)+ (*function)(b));
    for (int n = 1; n < N; n++)
    {
        value +=h* (*function)(a + n * h);
    }
    return value;
} 

double Mittelpunkt(double a, double b, int N, double (*function)(double)){
    double h = (b-a)/N;
    double value = 0;
    for (int n = 1; n < N; n++)
    {
        value += h *  (*function)(a + h * ( n + 0.5));
    }
    return value;
}

double Simpson(double a, double b, int N, double (*function)(double)){
    double h = (b - a)/N;
    double value = h/3.0 * ((*function)(a) + (*function)(b));
    for (int n = 1; n < N/2.0; n++)
    {
        value +=h * ( 4.0/3 * (*function)(a + (2*n-1)*h) + 2.0/3 * (*function)(a + 2 * h * n));
    }
    return value;
}

int main()
{
    double a = 1;
    double b = 100;
    double c = 0;
    double d = 1;

    cout<< Trapez(a, b, 8000, functiona) << "   " << Mittelpunkt(a,b,512000, functiona) << "   "<< Simpson(a,b,1000, functiona) <<endl;
    cout<< Trapez(c, d, 500, functionb) << "   " << Mittelpunkt(c,d,1000, functionb) << "   "<< Simpson(c,d,64000, functionb) <<endl;
    return 0;
}