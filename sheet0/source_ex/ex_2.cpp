#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double a(double x){
  return 1/sqrt(x) - 1/sqrt(x+1);
}

double b(double x){
  return (1 - cos(x))/sin(x);
}

double c(double x, double delta){
  return sin(x+delta) - sin(x);
}

int main () {
  ofstream myfile ("source_ex/output/ex_1.txt");
  if (myfile.is_open())
  {
    myfile << "Hello World";
    myfile.close();
  }
  else cout << "Unable to open file";
  return 0;
}