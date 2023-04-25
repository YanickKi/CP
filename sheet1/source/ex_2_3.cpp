#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

//zuerst werden die Funktionen für die Aufgabe 3 definiert

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
//Hier werden die einzelnen VErfahren implementiert wobei die Funktionen über den Parameter (*funtion) übergeben werden könnem
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
    double f = 0.219384; //Kontrollwert 1 und 2
    double f2 = 0.378530 ;
   double Trapez1 =Trapez(a, b, 8000, functiona);
   double Trapez2 =Trapez(c, d, 500, functionb);
   double Mitte1 =Mittelpunkt(a,b,512000, functiona);
   double Mitte2 =Mittelpunkt(c,d,1000, functionb);
   double Simp1 = Simpson(a,b,1000, functiona);
   double Simp2 = Simpson(c,d,64000, functionb);


    cout<< Trapez(a, b, 8000, functiona) << "   " << Mittelpunkt(a,b,512000, functiona) << "   "<< Simpson(a,b,1000, functiona) <<endl;
    cout<< Trapez(c, d, 500, functionb) << "   " << Mittelpunkt(c,d,1000, functionb) << "   "<< Simpson(c,d,64000, functionb) <<endl;
    ofstream file("source/output/ex_2_3.txt");
    if (file.is_open()){
    file    << "Funktion a):" << endl;
    file    << "Trapez:\t" << Trapez(a, b, 8000, functiona)<< "   " << (f - Trapez1)/Trapez1  << "\t Mittelpunkt:\t" << Mittelpunkt(a,b,512000, functiona)<< "   " << (f - Mitte1)/Mitte1  << "\t Simpson:\t"<<Simpson(a,b,1000, functiona) << "   " << (f - Simp1)/Simp1 <<endl;
    file    << "Funktion b):" << endl;
    file    << "Trapez:\t" << Trapez(c, d, 500, functionb)<< "   " << (f2 - Trapez2)/Trapez2  << "\t Mittelpunkt:\t" << Mittelpunkt(c,d,1000, functionb) << "   " << (f2 - Mitte2)/Mitte2<< "\t Simpson:\t"<< Simpson(c,d,64000, functionb)<< "   " << (f2 - Simp2)/Simp2 <<endl;
    }
     else
    cout << "Unable to open file";
    return 0;
}