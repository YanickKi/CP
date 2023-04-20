#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <numbers>
using namespace std;


// write saves data to a txt

void write(vector<float>& arg, vector<float>& num, vector<float>& ana, string filename){
      ofstream file(filename.c_str());
  if (file.is_open()){
    file    << "arg\t"                              // create header for readability in txt 
            << "numerical\t"
            << "analytical\t"
            << "relative_error" << endl;

    for (int i = 0; i < arg.size(); i++)
    {
      file  << arg[i] << "\t" << num[i] << "\t" << ana[i] << "\t" << abs((num[i] - ana[i]) / ana[i]) << endl;
    }
  }
  else
    cout << "Unable to open file";
}

// calculate first derivative numerically with two point method 

void zweipunkt(vector<float>& deriv, vector<float>& x, float (*function)(float), float h){
    for (int i = 0; i < x.size(); i++){
        deriv.push_back(((*function)(x[i]+h) - (*function)(x[i]-h)) / (2*h));
    }
}

// calculate 2nd derivative numerically with two point method

void sec_zweipunkt(vector<float>& deriv, vector<float>& x, float (*function)(float), float h){
    for (int i = 0; i < x.size(); i++){
        deriv.push_back(((*function)(x[i]+2* h) - 2 * (*function)(x[i]) + (*function)(x[i]-2*h)) / (4* pow(h,2)));
    }
}

// calculate any derivative analytically, function is already the function of the derivative

void ana_deriv(vector<float>& ana, vector<float>& x, float (*function)(float)){
  for(int i = 0; i < x.size(); i++){
    ana.push_back((*function)(x[i]));
  }
}

int main(){

  //first part of a)

    float max_steps = 1000.0; // number of steps
    vector<float> num;        // save derivative, caluclated numerically

  // calculate derivative numerically in dependene on step size at x = 0

    for(int i = 0; i < max_steps; i++){
        num.push_back(
            (sin((i+1)/max_steps) - sin(-(i+1)/max_steps)) / (2 * (i+1)/max_steps)
        );                                                                            
    }

    // saving in txt

    ofstream file("source/output/ex_1a.txt");
    if (file.is_open()){
    file    << "arg\t"
            << "numerical\t" 
            << endl;
    for (int i = 0; i < num.size(); i++)
    {
      file  << (i+1)/max_steps << "\t" << num[i] << endl;
    }
  }
  else
    cout << "Unable to open file";

  // 2nd half of a)

  vector<float> x, ana; // x-values and a vector to save the analytical derivation
  num.clear();
  float h = 0.3; //step size for the rest of this exercise;

  for (int i = 0; i < max_steps; i++){
      x.push_back(-numbers::pi  + 2 * numbers::pi * i/max_steps);     // create vector of x-values for the rest of exercise 1
  } 
  
  zweipunkt(num, x, sin, h);
  ana_deriv(ana, x, cos);
  write(x, num, ana, "source/output/ex_1a_error.txt");

  // part b)

  num.clear();
  ana.clear();

  //sec_zweipunkt(num, x, sin, h);
  //ana_deriv(ana, x, sin));
  //
  //return 0;

}
/* 

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <numbers>
using namespace std;

void zweipunkt(vector<float> &deriv, float upper, float lower, float step_size)
{
  deriv.push_back((upper - lower) / (2 * step_size));
}

void zweipunkt_second(vector<float> &sec_deriv, float upper, float mid, float lower, float step_size)
{
  sec_deriv.push_back((upper - 2 * mid + lower) / (4 * pow(step_size, 2)));
}

void vierpunkt(vector<float> &deriv, float upper, float up, float low, float lower, float step_size)
{
  deriv.push_back((-upper + 8 * up - 8 * low + lower) / (12 * step_size));
}

int main()
{
  // part a)

  float x = 0;              // x-value where the num_deriv will be calculated
  float max_steps = 1000.0; // number of steps
  vector<float> num_deriv;
  vector<float> f1; //  in depence on the step size in this half
  for (int i = 0; i < max_steps; i++)
  {
    f1.push_back(sin(x - (i + 1) / max_steps));
    f1.push_back(sin(x + (i + 1) / max_steps));
  }

  for (int i = 0; i < f1.size(); i += 2)
  {
    zweipunkt(num_deriv, f1[i + 1], f1[i], (i + 1) / max_steps);
  }

  ofstream myfile("source/output/ex_1a.txt");
  if (myfile.is_open())
  {
    for (int i = 0; i < num_deriv.size(); i++)
    {
      myfile << (i + 1) / max_steps << "\t" << num_deriv[i] << endl;
    }
  }
  else
    cout << "Unable to open file";

  float h = 0.3; // fixed step size for second half of part a)

  num_deriv.clear();
  f1.clear();              // for second half in depence on x
  vector<float> ana_deriv; // analytical results

  double num_points = max_steps; // just for readability
  for (int i = 0; i < num_points; i++)
  {
    f1.push_back(sin((-numbers::pi + 2 * numbers::pi * i / num_points - h)));
    f1.push_back(sin((-numbers::pi + 2 * numbers::pi * i / num_points + h)));
  }

  for (int i = 0; i < f1.size(); i += 2)
  {
    zweipunkt(num_deriv, f1[i + 1], f1[i], h);
  }

  for (int i = 0; i < num_points; i++)
  {
    ana_deriv.push_back(cos(-numbers::pi + 2 * numbers::pi * i / num_points));
  }

  ofstream error("source/output/ex_1a_error.txt");
  if (error.is_open())
  {
    error << "x\t"
          << "numerical\t"
          << "analytical\t"
          << "relative_error" << endl;
    for (int i = 0; i < num_deriv.size(); i++)
    {
      error << -numbers::pi + 2 * numbers::pi * i / num_points << "\t" << num_deriv[i] << "\t"
            << ana_deriv[i] << "\t" << abs((num_deriv[i] - ana_deriv[i]) / ana_deriv[i]) << endl;
    }
  }
  else
    cout << "Unable to open file";

  // part b)

  vector<float> num_sec_deriv;
  vector<float> ana_sec_deriv;

  f1.clear();

  for (int i = 0; i < num_points; i++)
  {
    f1.push_back(sin((-numbers::pi + 2 * numbers::pi * i / num_points - 2 * h)));
    f1.push_back(sin((-numbers::pi + 2 * numbers::pi * i / num_points)));
    f1.push_back(sin((-numbers::pi + 2 * numbers::pi * i / num_points + 2 * h)));
  }

  for (int i = 0; i < f1.size(); i += 3)
  {
    zweipunkt_second(num_sec_deriv, f1[i + 2], f1[i + 1], f1[i], h);
  }

  for (int i = 0; i < num_points; i++)
  {
    ana_sec_deriv.push_back(-sin(-numbers::pi + 2 * numbers::pi * i / num_points));
  }

  ofstream sec_deriv("source/output/ex_1b.txt");
  if (sec_deriv.is_open())
  {
    sec_deriv << "x\t"
              << "numerical\t"
              << "analytical\t"
              << "relative_error" << endl;
    for (int i = 0; i < num_sec_deriv.size(); i++)
    {
      sec_deriv << -numbers::pi + 2 * numbers::pi * i / num_points << "\t" << num_sec_deriv[i] << "\t"
                << ana_sec_deriv[i] << "\t" << abs((num_sec_deriv[i] - ana_sec_deriv[i]) / ana_sec_deriv[i]) << endl;
    }
  }
  else
    cout << "Unable to open file";

  f1.clear();

  num_deriv.clear();

  for (int i = 0; i < num_points; i++)
  {
    f1.push_back(sin((-numbers::pi + 2 * numbers::pi * i / num_points - 2 * h)));
    f1.push_back(sin((-numbers::pi + 2 * numbers::pi * i / num_points -     h)));
    f1.push_back(sin((-numbers::pi + 2 * numbers::pi * i / num_points +     h)));
    f1.push_back(sin((-numbers::pi + 2 * numbers::pi * i / num_points + 2 * h)));
  }

  for(int i = 0; i < f1.size(); i += 4){
    vierpunkt(num_deriv, f1[i+3], f1[i+2], f1[i+1], f1[i], h);
  }

  ofstream vierpunkt_1("source/output/ex_1c.txt");
  if (sec_deriv.is_open())
  {
    vierpunkt_1 << "x\t"
              << "numerical\t"
              << "analytical\t"
              << "relative_error" << endl;
    for (int i = 0; i < num_sec_deriv.size(); i++)
    {
      vierpunkt_1 << -numbers::pi + 2 * numbers::pi * i / num_points << "\t" << num_deriv[i] << "\t"
                << ana_deriv[i] << "\t" << abs((num_deriv[i] - ana_deriv[i]) / ana_deriv[i]) << endl;
    }
  }
  else
    cout << "Unable to open file";

  vector<float> f2;
  vector<float> num_vier;

  num_deriv.clear();
  ana_deriv.clear();

  for(int i = 0; i < num_points; i++){
    x = -numbers::pi + 2 * numbers::pi * i / num_points; 
    if(x-h < 0){
      f2.push_back(2 * floor(x/(numbers::pi)) + cos(fmod(x, numbers::pi)) + 1);
    }  
    if(x-h >= 0){
      f2.push_back(2 * floor(x/(numbers::pi)) - cos(fmod(x, numbers::pi)) + 1);
    }

    if(x+h < 0){
      f2.push_back(2 * floor(x/(numbers::pi)) + cos(fmod(x, numbers::pi)) + 1);
    }

    if(x+h >= 0){
      f2.push_back(2 * floor(x/(numbers::pi)) - cos(fmod(x, numbers::pi)) + 1);
    }
  }
  for(int i = 0; i < f2.size(); i += 2){
  zweipunkt(num_deriv, f2[i+1], f2[i], h);
  }


  
  return 0;
}

// O pana!

*/