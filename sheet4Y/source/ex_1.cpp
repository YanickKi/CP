#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <numbers>
using namespace std;

double delta = 0.05, maxError = 1e-5;
int length = 1, N = length/delta; // N is number of points per row/coloumn

/*  the first index (coloumns) is for the x coordinate
    the second index (rows) is for the y coordinate */

void write(vector<vector<double>>& vec, string filename){
  ofstream file(filename.c_str());
    if (file.is_open()){
    for(int l = vec.at(0).size()-1; l >= 0; l--){
      /* start the summation from end, higher y will be up */
      for (int j = 0; j < vec.size(); j++){
        file << vec.at(j).at(l) << "\t";
      }
    file << endl;
    }
    file.close();
  }
  else
    cout << "Unable to open file";
}

void calcE(vector<vector<double>>& phi, vector<vector<double>>& E){
  for(int j = 1; j< N-1; j++){
    for(int l =1; l<N-1; l++){
      E.at(j).at(l) = - 1/(2*delta) * ( phi.at(j+1).at(l) -  phi.at(j-1).at(l) +  phi.at(j).at(l+1) -  phi.at(j).at(l-1));
    }
  }
}

void GaussSeidel(vector<vector<double>>& phi, vector<vector<double>>& rho){
  double tempPhi, errorSquared = maxError + 1; 
  while(errorSquared > maxError * maxError){
    errorSquared = 0;
    for(int j = 1; j<N-1; j++){
      for(int l =1; l<N-1; l++){
        tempPhi = phi.at(j).at(l);
        phi.at(j).at(l) = 1./4. * (phi.at(j).at(l+1) + phi.at(j).at(l-1) + phi.at(j+1).at(l) + phi.at(j-1).at(l) + delta * delta * rho.at(j).at(l));
        errorSquared += pow(phi.at(j).at(l) - tempPhi, 2);
      }
    }
  }
}

int main (){
  /* Aufgabenteil b) */
  double delta = 0.05, maxError = 1e-5;
  int length = 1;
  int N = length/delta; // number of points per row/coloumn
  vector<vector<double>> phi (N, vector<double>(N, 1));
  vector<vector<double>> rho (N, vector<double>(N, 0));
  // boundary conditions 
  for(int i = 0; i < N; i++){
    phi.at(0).at(i)    = 0;
    phi.at(i).at(0)    = 0;
    phi.at(i).at(N-1)  = 0;
    phi.at(N-1).at(i)  = 0;
  }

  GaussSeidel(phi, rho);
  write(phi, "source/output/1b.txt");

  fill(phi.begin(), phi.end(), vector<double> (N,1));
  fill(rho.begin(), rho.end(), vector<double> (N,0));

  /* Aufgabenteil c) */

  for(int i = 0; i < N; i++){
    phi.at(0).at(i)    = 0;
    phi.at(i).at(0)    = 0;
    phi.at(N-1).at(i)  = 0;
    phi.at(i).at(N-1)  = 1;
  }

  GaussSeidel(phi, rho);
  write(phi, "source/output/1c.txt");

  fill(phi.begin(), phi.end(), vector<double> (N,0));

  for(int j = 0; j < N; j++){
    for(int l = 0; l < N; l++){
      for(int n = 1; n <= 100; n++){
        phi.at(j).at(l) += (2*(1-cos(n*numbers::pi)))/(n*numbers::pi*sinh(n*numbers::pi))*sin(n*numbers::pi*j*delta)*sinh(n*numbers::pi*l*delta);      }
    }
  }
  
  write(phi, "source/output/1c_analytical.txt");
  
  /* Aufgabenteil d) */

  vector<vector<double>> E (N, vector<double>(N, 0));

  fill(phi.begin(), phi.end(), vector<double> (N,0));
  rho.at(N/2-1).at(N/2-1) = 1;

  GaussSeidel(phi, rho);
  calcE(phi, E);
  write(phi, "source/output/1d.txt");
  write(E, "source/output/1d_E.txt");

  /* Aufgabenteil e) */

  fill(phi.begin(), phi.end(), vector<double> (N,0));
  rho.at(N/2-1).at(N/2-1) = 0;

  for(int i = 0; i <= 1; i++){
    for(int j = 0; j <= 1; j++){
    rho.at(N/4 + i * N/2 - 1 ).at(N/4 + j * N/2 - 1) = pow(-1, i+j);
    }
  }

  GaussSeidel(phi, rho);
  calcE(phi, E);
  write(phi, "source/output/1e.txt");
  write(E, "source/output/1e_E.txt");
  return 0;
}