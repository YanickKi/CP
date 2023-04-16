#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;



void vierpunkt(vector <double>& derivative, vector<double>& func, int max_steps){
  for(int i = 1; i < max_steps; i += 2)
  derivative.push_back(
    (func[i] - func[i-1])/(i/max_steps)
  );
}

int main () {
  //part a)

  double x = 0; // x-value where the derivative will be calculated
  double max_steps = 1000.0; //step size
  vector<double> derivative;
  vector<double> f1;
  for(int i = 1; i<max_steps; i++){
    f1.push_back(sin(x+i/max_steps));
    f1.push_back(sin(x-i/max_steps));
  }
  
vierpunkt(derivative, f1, max_steps);



  ofstream myfile ("source/output/ex_1a.txt");
  if (myfile.is_open())
  {
    for(int i = 1; i < derivative.size(); i++){
      myfile << i/max_steps << "\t" << derivative[i] << endl;
    } 

  }
  else cout << "Unable to open file";
  return 0;
}