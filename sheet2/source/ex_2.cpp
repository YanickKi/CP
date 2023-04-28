#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

void equations(vector<double>& vec, double r, double z, double psi, vector<double>& params){
  //cout <<"in equation" <<endl;
  vec.push_back(cos(psi));
  vec.push_back(sin(psi));
  //cout << "r = " << r <<endl;
  if(r == 0){
    vec.push_back((params[0] - params[1])/2. * z);
  }
  else{
    vec.push_back(params[0] - params[1] * z - sin(psi) / r);
  }
  //cout <<  "vec[2]" <<vec[2] <<endl;


}

void RK4(vector<vector<double>>& val, vector<double>& init, vector<double>& params, double step_size){

  /* #### order of coloumns of vector val: r, z, psi #### */

  // add initial conditions

  val.push_back(init);

  // actual caclulation of vector<double>&the vector

  vector<double> k1{}, k2{}, k3{}, k4{}, temp{};
  int iter = 0;

  while(val[iter][0] < 1./2.){ // iter < val[0].size()

    //cout << "\tIteration = " << iter << endl;

    equations(k1, val[iter][0], val[iter][1], val[iter][0], params);
    equations(k2, val[iter][0] + 1./2. * k1[0], val[iter][1] + 1./2. * k1[1] , val[iter][2] + 1./2. * k1[2], params);
    equations(k3, val[iter][0] + 1./2. * k2[0], val[iter][1] + 1./2. * k2[1] , val[iter][2] + 1./2. * k2[2], params);
    equations(k4, val[iter][0] +  k3[0], val[iter][1] + k3[1] , val[iter][2] + k3[2], params);
    for(int i = 0; i < k1.size(); i++){
      temp.push_back(val[iter][i] + 1./6. * step_size * ( k2[i] + 2 * k2[i] + 2 * k3[i] + k4[i]));
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

  double step_size = 0.0001;
  vector<vector<double>> vec{};
  vector<double>init = {0.1,0.,0.}, params = {2., 0.1};

  RK4(vec, init, params, step_size);

  ofstream myfile ("source/output/ex_2c.txt");

  if (myfile.is_open())
  {
    myfile << "s\t" << "r\t" << "z\t" << "psi" << endl;
    for(int i = 0; i < vec.size(); i++){
      myfile << step_size * i;
      for(int j = 0; j < 3; j++){
        myfile << "\t" << vec[i][j] << "\t";//HIER CHECKEN OB ES DIE RICHTIGEN ELEMENTE SIND
      }
      myfile << endl;
    }
    myfile.close();
  }
  else cout << "Unable to open file";
  return 0;
}