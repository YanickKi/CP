#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;



void vierpunkt(vector <double>& derivative, vector<double>& func, double max_steps){
  for(int i = 0; i < max_steps; i += 2){
  //cout << "TOP: " << func[i] << "\tBOT: " << func[i-1] << "\tstep: " << i/max_steps << endl;
  derivative.push_back((func[i+1] - func[i])/((i+1)/max_steps));
  }
}

int main () {
  //part a)
 
  double x = 0; // x-value where the derivative will be calculated
  double max_steps = 1000.0; //step size
  vector<double> derivative;
  vector<double> f1;
  for(int i = 0; i<max_steps; i++){
    f1.push_back(sin(x-(i+1)/max_steps));
    f1.push_back(sin(x+(i+1)/max_steps));
  }
  
vierpunkt(derivative, f1, max_steps);

  ofstream myfile ("source/output/ex_1a.txt");
  if (myfile.is_open())
  {
    for(int i = 0; i < derivative.size(); i++){
      myfile << (i+1)/max_steps << "\t" << derivative[i] << endl;
    } 

  }
  else cout << "Unable to open file";

 double h = 0.144; // fixed step size for second half of part a)

  return 0;
}