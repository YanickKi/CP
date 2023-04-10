#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double a(double x){
  return 1/sqrt(x) - 1/sqrt(x+1);
}

double a_new(double x){
  return 1/(x * sqrt(x+1) + sqrt(x)*(x+1));
}

double b(double x){
  return (1 - cos(x))/sin(x);
}

double b_new(double x){
  return sin(x)/(1+cos(x));
}

double c(double x, double delta){
  return sin(x+delta) - sin(x);
}

double c_new(double x, double delta){
  return (cos(x) * sin(delta) + ( sin(x) * pow(sin(delta),2))/(cos(delta)+1));
}

int main () {
  ofstream myfile ("source_ex/output/ex_2.txt");
  if (myfile.is_open())
  {
    myfile << "Hello World";
    myfile.close();
  }
  else cout << "Unable to open file";
  return 0;
}