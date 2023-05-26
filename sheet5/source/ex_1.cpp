#include <iostream>
#include <fstream>
#include </home/yanick/.include/Eigen/Dense>
#include <numbers>
using namespace std;

const double dxi = 0.1, dtau = 0.02;
const int D = 20/dxi+1, timeSteps = 20/dtau;
Eigen::VectorXd xi = Eigen::VectorXd::LinSpaced(D,-10,10);

void write(Eigen::VectorXd & vector, string filename){
  ofstream file(filename.c_str());
    if (file.is_open()){
    for(int l = 0; l < vector.size(); l++){
        file << vector(l) << endl;
      }
    file.close();
  }
  else
    cout << "Unable to open file";
}


Eigen::MatrixXcd timeEv(){
  Eigen::MatrixXd nmMinus1 = Eigen::MatrixXd::Zero(D,D), nmPlus1 = Eigen::MatrixXd::Zero(D,D), unitMatrix = Eigen::MatrixXd::Identity(D,D);
  // make chronecker delta matrix

  for(int n = 0; n < D-1; n++){
    nmMinus1(n,n+1) = 1;
  }
  for(int n = 1; n < D; n++){
    nmPlus1(n,n-1)  = 1;
    }
  Eigen::MatrixXd hinten = Eigen::MatrixXd::Zero(D,D);

  for(int n = 0; n < D; n++){
    hinten(n,n) = (n-100)*(n-100);
  }
 // calculate Hamilton Matrix
  Eigen::MatrixXd H(D,D);
  H = - (nmMinus1 + nmPlus1 - 2 * unitMatrix) / (dxi*dxi) + dxi * dxi * hinten;

  //calculate time Evolution matrix

  Eigen::MatrixXcd tempInv = unitMatrix + complex<double>(0,1) * H * dtau;
  Eigen::MatrixXcd temp = unitMatrix - complex<double>(0,1) * H * dtau;
  Eigen::MatrixXcd SH = tempInv.inverse() * temp;
  return SH;
}
int main (){  

  Eigen::VectorXcd psi(D);
  Eigen::MatrixXcd SH = timeEv();
  Eigen::VectorXd probDens(D);
  //initilize stat
  for(int i = 0; i < D; i++){
    psi(i) = pow(1/(2*numbers::pi), 1./4.) * exp(-pow(xi(i) - 1,2)/4);
    probDens(i) = norm(psi(i));
  }

  write(probDens, "source/output/1c_" + to_string(0) + ".txt");

  //calculate the state after time Steps and save the probality desnity

  for(int n = 1; n <= timeSteps; n++){
    psi = SH * psi;
  for(int i = 0; i < D; i++){
    probDens(i) = norm(psi(i));
  }
    write(probDens, "source/output/1c_" + to_string(n) + ".txt");
  }

  return 0;
}