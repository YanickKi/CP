#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const double dt = 0.00001, dx = 0.01, D = 1;
const int timeSteps = 1000, length = 1, N = length/dx; // N is number of spacial points


/*  the first index (coloumns) is the time
    the second index (rows) is spacial      */


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

void FTCS(vector<vector<double>>& u, vector<double>& uInit){
    u.at(0) = uInit;
    for(int n = 0; n < timeSteps-1; n++){
        for(int j = 1; j < N-1 ;j++){
            u.at(n+1).at(j) = u.at(n).at(j) + D * dt/(dx * dx) * (u.at(n).at(j+1) - 2 * u.at(n).at(j) + u.at(n).at(j-1));
        }
    }
}

int main(){

    vector<vector<double>> u(timeSteps, vector<double>(N));
    vector<double> uInit(N, 1);

    /* Aufgabenteil a) */

    FTCS(u, uInit);
    write(u, "source/output/2a.txt");  

    /* Aufgabenteil b) */

    fill(uInit.begin(), uInit.end(), 0);

    uInit.at(N/2-1) = 1;


    return 0;
}