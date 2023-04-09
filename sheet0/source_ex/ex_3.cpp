#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<double> values;

int main () {
        double steps = 1000.0;
        double val = 0, temp = 0;
    for(int n = 0; n < steps; n++){
        if(n == 0){
            temp = 1;
        }
        val = temp*(1 - 10/steps);
        temp = val;
        values.push_back(val);
    }
    ofstream symm ("source_ex/output/ex_3_symm.txt");
    if (symm.is_open())
    {
        for(int i = 0; i < values.size(); i++){
            symm << values[i] << endl;
        }
        symm.close();
    }
    else cout << "Unable to open file";

  return 0;
}