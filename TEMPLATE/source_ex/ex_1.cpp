#include <iostream>
#include <fstream>
using namespace std;

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