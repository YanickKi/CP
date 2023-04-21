#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <numbers>
#include <functional>
using namespace std;


// write saves data to a txt

void write(vector<float>& arg, vector<float>& num, vector<float>& ana, string filename){
      ofstream file(filename.c_str());  // iostream functions deal with const char* rather than string
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

// calculate 1st derivative numerically with two point method 

void zweipunkt(vector<float>& deriv, vector<float>& x, float (*function)(float), float h){
    for (int i = 0; i < x.size(); i++){
        deriv.push_back(((*function)(x[i]+h) - (*function)(x[i]-h)) / (2*h));
    }
}

//calculate 1st derivative with four point rule

void vierpunkt(vector<float>& deriv, vector<float>& x, float (*function)(float), float h){
    for (int i = 0; i < x.size(); i++){
        deriv.push_back(
          (-(*function)(x[i]+2*h) + 8*(*function)(x[i]+h) - 8 * (*function)(x[i]-h) + (*function)(x[i]-2*h)) / (12*h)
          );
    }
}

// calculate 2nd derivative numerically with two point method

void sec_zweipunkt(vector<float>& deriv, vector<float>& x, float (*function)(float), float h){
    for (int i = 0; i < x.size(); i++){
        deriv.push_back(((*function)(x[i]+2* h) - 2 * (*function)(x[i]) + (*function)(x[i]-2*h)) / (4* pow(h,2)));
    }
}

// calculate any function analytically

void ana_deriv(vector<float>& ana, vector<float>& x, float (*function)(float)){
  for(int i = 0; i < x.size(); i++){
    ana.push_back((*function)(x[i]));
  }
}

// define function f2 from sheet

float f2(float x){
  if(x>= 0){
    return 2 * floor(x/numbers::pi) - cos(fmod(x, numbers::pi)) + 1;
  }
  else{
    return 2 * floor(x/numbers::pi) + cos(fmod(x, numbers::pi)) + 1;
  }
}

int main(){

  /* ############################# part a) ############################# */

  //first half of a)

    float max_steps = 1000.0; // number of steps
    vector<float> num;        // vector for derivative, calculated numerically

  // calculate derivative numerically in dependence on step size at x = 0

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
  float h = 1e-2; // step size for the rest of this exercise;

  for (int i = 0; i < max_steps; i++){
      x.push_back(-numbers::pi  + 2 * numbers::pi * i/max_steps);     // create vector of x-values for the rest of exercise 1
  } 
  
  zweipunkt(num, x, sin, h);
  ana_deriv(ana, x, cos);
  write(x, num, ana, "source/output/ex_1a_error.txt");

  /* ############################# part b) ############################# */

  num.clear();
  ana.clear();

  sec_zweipunkt(num, x, sin, h);
  ana_deriv(ana, x, [] (float y) { return - sin(y) ;});
  write(x, num, ana, "source/output/ex_1b.txt");

  /* ############################# part c) ############################# */

  num.clear();
  ana.clear();

  vierpunkt(num, x, sin, h);
  ana_deriv(ana, x, cos);
  write(x, num, ana, "source/output/ex_1c.txt");

    /* ############################# part d) ############################# */


  vector<float> twopoint;   // save derivative from two- and fourpoint in new vectors for readability
  vector<float> fourpoint;

  zweipunkt(twopoint, x, f2, h);  
  vierpunkt(fourpoint, x, f2, h); 

  /* care: there is no analytial derivation here, instead it is the numerical 
  derivation with the fourpoint rule, when writing to txt */

  write(x, fourpoint, twopoint, "source/output/ex_1d.txt"); 

  return 0;
}