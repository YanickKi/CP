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

  float x;
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