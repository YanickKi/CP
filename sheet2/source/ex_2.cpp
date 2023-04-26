#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

void equations(vector<double>& vec, double r, double z, double psi, vector<double>& params){
  vec.push_back(cos(psi));
  vec.push_back(sin(psi));
  vec.push_back(params[0] - params[1] * z - sin(psi) / r);
}

void RK4(vector<vector<double>>& val, vector<double>& init, vector<double>& params, double step_size){

  /* #### order of coloumns of vector val: r, z, psi #### */

  // add initial conditions

  val.push_back(init);
  cout << " loloololol" << val.size();
  
  // actual caclulation of the vector

  vector<double> k1, k2, k3, k4, temp;
  int iter = 0;
  while(val[0][iter] < 1/2){
    equations(k1, val[0][iter], val[1][iter], val[2][iter], params);
    equations(k2, val[0][iter] + 1/2 * k1[0], val[1][iter] + 1/2 * k1[1] , val[2][iter] + 1/2 * k1[2], params);
    equations(k3, val[0][iter] + 1/2 * k2[0], val[1][iter] + 1/2 * k2[1] , val[2][iter] + 1/2 * k2[2], params);
    equations(k4, val[0][iter] +  k3[0], val[1][iter] + k3[1] , val[2][iter] + k3[2], params);
    for(int i = 0; i < k1.size(); i++){
      temp.push_back(val[i][iter] + 1/6 * step_size * ( k2[i] + 2 * k2[i] + 2 * k3[i] + k4[i]));
    }
    val.push_back(temp);
    k1.clear();
    k2.clear();
    k3.clear();
    k4.clear();
    temp.clear();
    iter += 1;
  }
}


int main () {
    cout <<"Bisher hierhin gehts!" << endl;

  double step_size = 0.01;
  vector<vector<double>> vec;
  vector<double>init(3), params(2);
  params[0] = 2;
  params[1] = 0.1;
  init[0] = 0; 
  init[1] = 0;
  init[2] = 0;
  cout <<"Bisher hierhin gehts!" << endl;

  RK4(vec, init, params, step_size);

  cout << "lol" << endl;
  cout << "vecsize " << vec[0].size(); 
  ofstream myfile ("source/output/ex_2a.txt");
  if (myfile.is_open())
  {
    myfile << "r\t" << "z\t" << "psi" << endl;
    for(int i = 0; i < vec[0].size(); i++){
      for(int j = 0; j < 3; j++){
        myfile << vec[j][i] << "\t";
      }
      myfile << endl;
    }
    myfile.close();
  }
  else cout << "Unable to open file";
  return 0;
}