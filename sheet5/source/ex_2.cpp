#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <numbers>

using namespace std;

/* first index is time, second index is x, third index is y*/


const double a = 1, b = 1.5, dx = 1e-2, dy = 1e-2, dt = 1e-5; // dimensions of the membrane and the spacial/time steps
const int maxTimeSteps = 1000, Nx = a/dx, Ny = b/dy; // number of steps in time and spacial directions


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


void iterationScheme(vector<vector<vector<double>>>& u, vector<vector<double>>& uInit){
    u.at(0) = uInit; // initialize u

    // use the inital condtion \partial_t u |_{t=0} = 0, i.e. calculate the second time step
    for(int i = 1; i < Nx-1; i++){
        for(int j = 1; j < Ny-1; j++){
            u.at(1).at(i).at(j) = dt * dt/2 * (
                1/(dx * dx) * (u.at(0).at(i+1).at(j) - 2 * u.at(0).at(i).at(j) + u.at(0).at(i-1).at(j)) +
                1/(dy * dy) * (u.at(0).at(i).at(j+1) - 2 * u.at(0).at(i).at(j) + u.at(0).at(i).at(j-1))
            ) + u.at(0).at(i).at(j);

        }
    }

    // iteration procedure for the rest of the time steps
    for(int n = 2; n < maxTimeSteps - 1; n++){
        //if((n-99) % 100 == 0){
        write(u.at(n), "source/output/2e_" + to_string(n) + ".txt");
        //}

        for(int i = 2; i < Nx-1; i++){
            for(int j = 1; j < Ny-1; j++){
                u.at(n+1).at(i).at(j) = dt * dt * (
                    1/(dx * dx) * (u.at(n).at(i+1).at(j) - 2 * u.at(n).at(i).at(j) + u.at(n).at(i-1).at(j)) +
                    1/(dy * dy) * (u.at(n).at(i).at(j+1) - 2 * u.at(n).at(i).at(j) + u.at(n).at(i).at(j-1))
                ) + 2 * u.at(n).at(i).at(j) - u.at(n-1).at(i).at(j);
            }
        }
    }
}

using namespace std;

int main(){

    vector<vector<vector<double>>> u(maxTimeSteps, vector<vector<double>>(Nx, vector<double> (Ny)));
    vector<vector<double>> uInit(Nx, vector<double> (Ny));

    for(int i = 0; i < Nx; i++){
        for(int j = 0; j < Ny; j++){
            uInit.at(i).at(j) = sin(numbers::pi / a * i *dx) * sin(2 * numbers::pi / b * j *dy);
        }
    }

    iterationScheme(u, uInit);
    write(u.at(0), "source/output/2e_" + to_string(0) + ".txt");
    write(u.at(1), "source/output/2e_" + to_string(1) + ".txt");
    write(u.at(999), "source/output/2e_" + to_string(999) + ".txt");
    //write(u.at(10), "source/output/2e_" + to_string(10) + ".txt");
    //write(u.at(5), "source/output/2e_" + to_string(5) + ".txt");

    return 0;
}