#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

void a(vector<double>& x, vector<double>& store){
  for(int i = 0; i < x.size(); i++){
    store.push_back(1/sqrt(x[i]) - 1/sqrt(x[i]+1));
  }
}

void a_new(vector<double>& x, vector<double>& store){
  for(int i = 0; i < x.size(); i++){
    store.push_back(1/(x[i] * sqrt(x[i]+1) + sqrt(x[i])*(x[i]+1)));
  }
}

void b(vector<double>& x, vector<double>& store){
  for(int i = 0; i < x.size(); i++){
    store.push_back((1 - cos(x[i]))/sin(x[i]));
  }
}

void b_new(vector<double>& x, vector<double>& store){
  for(int i = 0; i < x.size(); i++){
    store.push_back(sin(x[i])/(1+cos(x[i])));
  }
}

void c(vector<double>& x, double delta, vector<double>& store){
  for(int i = 0; i < x.size(); i++){
    store.push_back(sin(x[i]+delta) - sin(x[i]));
  }
}

void c_new(vector<double>& x, double delta, vector<double>& store){
  for(int i = 0; i < x.size(); i++){
    store.push_back((cos(x[i]) * sin(delta) + ( sin(x[i]) * pow(sin(delta),2))/(cos(delta)+1)));
  }
}

void rel_err(vector<double>& bad, vector<double>& good, vector<double>& rel){
  for(int i = 0; i < bad.size(); i++){
    rel.push_back(abs((bad[i]-good[i])/good[i]) * 100);
  }
}

int main() {

  vector<double> x_small, x_big, x_period, a_bad, a_good, b_bad, b_good, c_bad, c_good, a_rel, b_rel, c_rel;
  for(int i = 0; i < 1000000; i++){
    x_small.push_back(1e-8 +  5 * i/100000000000000.0);
    x_big.push_back(1e12+ i/1000000.0);
    x_period.push_back(3.14 - i/1000000.0);
  }
  a(x_big, a_bad);
  a_new(x_big, a_good);
  b(x_small, b_bad);
  b_new(x_small, b_good);
  c(x_period, 1e-10, c_bad);
  c_new(x_period, 1e-8, c_good);
  rel_err(a_bad, a_good, a_rel);
  rel_err(b_bad, b_good, b_rel);
  rel_err(c_bad, c_good, c_rel);

  ofstream data ("source_ex/output/ex_2.txt");
  if (data.is_open())
  {
    data << "x_small\t" << "x_big\t" << "x_period\t" << "a_bad\t" << "a_good\t" << "b_bad\t" << "b_good\t" << "c_bad\t" << "c_good\t" << "a_rel\t" << "b_rel\t" << "c_rel\t" << endl;
    for (int i = 0; i < x_small.size(); i++)
        {
          data << fixed << setprecision(9) << x_small[i]  << "\t"  << x_big[i]  << "\t" << x_period[i]  << "\t"<< a_bad[i] << "\t" 
          << a_good[i] << "\t" << b_bad[i] << "\t" << b_good[i]
          << "\t" << c_bad[i] << "\t" << c_good[i] << "\t" << a_rel[i] << "\t" << b_rel[i] << "\t" << c_rel[i] << endl;
        }
    data.close();
  }
  else cout << "Unable to open file";
  return 0;
}