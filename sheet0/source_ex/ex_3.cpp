#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

//vector<double> euler(int steps, double y0){
//
//}
//
//vector<double> symm_euler(int steps, double y0, double y1){
//
//}

vector<double> normal_values, symm_values;

int main()
{
    double steps = 150.0;
    double val = 1;
    double temp = val;
    
    for (int n = 0; n < steps; n++)
    {
        normal_values.push_back(val);
        val = temp * (1 - 10 / steps);
        temp = val;
    }

    double temp_2 = 1, new_temp_2 = 1;
    temp = exp(-10/steps);
    for (int n = 0; n < steps; n++)
    {
        if(n == 0){
            symm_values.push_back(temp_2);
            continue;
        }
        if (n == 1)
        {
            symm_values.push_back(exp(-10/steps));
            temp_2 = 1;
            temp = exp(-10/steps);
            continue;   
        }
        val = -2 * 10/steps * temp + temp_2;
        temp_2 = temp;
        temp = val;
        symm_values.push_back(val);
    }
    ofstream euler("source_ex/output/ex_3_euler.txt");
    if (euler.is_open())
    {
        for (int i = 0; i < normal_values.size(); i++)
        {
            euler << normal_values[i] << "\t" << symm_values[i] << endl;
        }
        euler.close();
    }
    else
        cout << "Unable to open file";

    return 0;
}