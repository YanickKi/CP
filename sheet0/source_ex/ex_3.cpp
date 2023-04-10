#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

void euler(vector<double>& values, int steps, double y0){
    values.push_back(y0);
    for (int n = 0; n < steps - 1; n++)
    {   
        values.push_back(values[n]*(1-10.0/steps));
    }
} 

void symm_euler(vector<double>& values, int steps, double y0, double y1){
    values.push_back(y0);
    values.push_back(y1);   
    for (int n = 1; n < steps - 1; n++)
    {           
        values.push_back(-2*values[n]*10.0/steps + values[n-1]);
    }
}

vector<double> normal_values, symm_values;

int main()
{
    int steps = 150;
    euler(normal_values, steps, 1);
    symm_euler(symm_values, steps, 1, exp(-10/steps));

    ofstream euler_small("source_ex/output/ex_3_euler_small.txt");
    if (euler_small.is_open())
    {
        for (int i = 0; i < normal_values.size(); i++)
        {
            euler_small << normal_values[i] << "\t" << symm_values[i] << endl;
        }
        euler_small.close();
    }
    normal_values.clear();
    symm_values.clear();

    steps = 1e5;
    euler(normal_values, steps, 1);
    symm_euler(symm_values, steps, 1, exp(-10/steps));
 
    ofstream euler_big("source_ex/output/ex_3_euler_big.txt");
    if (euler_big.is_open())
    {
        for (int i = 0; i < normal_values.size(); i++)
        {
            euler_big << normal_values[i] << "\t" << symm_values[i] << endl;
        }
        euler_big.close();
    }
    else
        cout << "Unable to open file";

    //AUFGABENTEIL b)

    normal_values.clear();
    symm_values.clear();

    steps = 150;

    euler(normal_values, steps, 1-10.0/steps);
    symm_euler(symm_values, steps, 1, 1-10.0/steps);

    ofstream euler_small_b("source_ex/output/ex_3_euler_small_b.txt");
    if (euler_small_b.is_open())
    {
        for (int i = 0; i < normal_values.size(); i++)
        {
            euler_small_b << normal_values[i] << "\t" << symm_values[i] << endl;
        }
        euler_small_b.close();
    }
    normal_values.clear();
    symm_values.clear();

    steps = 1e5;
    euler(normal_values, steps, 1-10.0/steps);
    symm_euler(symm_values, steps, 1, 1-10.0/steps);
 
    ofstream euler_big_b("source_ex/output/ex_3_euler_big_b.txt");
    if (euler_big_b.is_open())
    {
        for (int i = 0; i < normal_values.size(); i++)
        {
            euler_big_b << normal_values[i] << "\t" << symm_values[i] << endl;
        }
        euler_big_b.close();
    }
    else
        cout << "Unable to open file";

    return 0;
}