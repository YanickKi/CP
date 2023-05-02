#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <math.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

//h ist Schrittbreite und T die Endzeit
// y = (x1, y1, x2, y2, x'1, y'1, x'2, y'2)
// 
// f = (y(4), y(5), y(6), y(7), Kräfte von x, y eins und zwei)





void Euler(int T, double h, vector<double>& y){
  int N = T/h;
  for (int i = 0; i < 8 * N; i++)
  if (i % 8 < 4){ //für alle einfachen x und y koordinaten
    y.push_back(y[i] + h * y[i+4]);
  } else if(i % 8 == 4 ){ // Die zweiten ableitungen--> Also die Kräfte auf x1, y1, x2, y2
    y.push_back(y[i] + h * (- 2.0/pow((pow((y[i-4]-y[i-2]),2) + pow((y[i-3]-y[i-1]),2)), (3/2.0)) * (y[i-4]- y[i-2]))); 
  } else if(i % 8 == 5 ){
    y.push_back(y[i] + h * (- 2.0/pow((pow((y[i-5]-y[i-3]),2) + pow((y[i-4]-y[i-2]),2)), (3/2.0)) * (y[i-4]- y[i-2])));
  } else if(i % 8 == 6 ){
    y.push_back(y[i] + h * (  1.0/pow((pow((y[i-6]-y[i-4]),2) + pow((y[i-5]-y[i-3]),2)), (3/2.0)) * (y[i-6]- y[i-4]))); 
  } else if(i % 8 == 7 ){
    y.push_back(y[i] + h * (  1.0/pow((pow((y[i-7]-y[i-5]),2) + pow((y[i-6]-y[i-4]),2)), (3/2.0)) * (y[i-6]- y[i-4])));
}
}

// Verlet mit Vektoren für Orte und Geschwindigkeiten einzeln
void Verlet(int T, double h, vector<double>& y, vector<double>& v){
  int N = T/h;
  //Startwerte einzeln zuerst da x_n-1 benötigt wird
  y.push_back(y[0] + v[0]*h + pow(h,2) * 1/2.0 * (- 2.0/pow((pow((y[0]-y[2]),2) + pow((y[1]-y[3]),2)), (3/2.0)) * (y[0]- y[2]))); // x_1 mit 
  y.push_back(y[1] + v[1]*h + pow(h,2) * 1/2.0 * (- 2.0/pow((pow((y[0]-y[2]),2) + pow((y[1]-y[3]),2)), (3/2.0)) * (y[1]- y[3]))); // y_1_
  y.push_back(y[2] + v[2]*h + pow(h,2) * 1/2.0 * (  1.0/pow((pow((y[0]-y[2]),2) + pow((y[1]-y[3]),2)), (3/2.0)) * (y[0]- y[2]))); // x_2_
  y.push_back(y[3] + v[3]*h + pow(h,2) * 1/2.0 * (  1.0/pow((pow((y[0]-y[2]),2) + pow((y[1]-y[3]),2)), (3/2.0)) * (y[1]- y[3]))); // y_2_
  //Hier die Iterationen für x und v
  for (int i = 4; i < 4 * N; i++){
    if ( i % 4 == 0){
      y.push_back(2* y[i] - y[i - 4] + pow(h,2) * (- 2.0/pow((pow((y[i  ]-y[i+2]),2) + pow((y[i+1]-y[i+3]),2)), (3/2.0)) * (y[i]- y[i + 2]))); // x_1_
    } else if ( i % 4 == 1){
      y.push_back(2* y[i] - y[i - 4] + pow(h,2) * ( -2.0/pow((pow((y[i-1]-y[i+1]),2) + pow((y[i  ]-y[i+2]),2)), (3/2.0)) * (y[i]- y[i + 2])));
    } else if ( i % 4 == 2){
      y.push_back(2* y[i] - y[i - 4] + pow(h,2) * ( -1.0/pow((pow((y[i-2]-y[i  ]),2) + pow((y[i-1]-y[i+1]),2)), (3/2.0)) * (y[i]- y[i - 2])));
    } else if ( i % 4 == 3){
      y.push_back(2* y[i] - y[i - 4] + pow(h,2) * ( -1.0/pow((pow((y[i-3]-y[i-1]),2) + pow((y[i-2]-y[i  ]),2)), (3/2.0)) * (y[i]- y[i - 2])));
    }
  }
  for (int j = 4; j < (4 * N) - 4; j++){
    v.push_back( 1.0/(2*h) * (y[j+4] - y[j-4]));
  }
}



int main()
{
  vector<double> y = {0, 1, 0, -0.5, 0.8, 0, -0.4, 0};
  vector<double> x = {0, 1, 0, -0.5};
  vector<double> v = {0.8, 0, -0.4, 0};
  
  double h_gut = 0.0001;
  double h_schlecht = 0.1;
  double h_vertrau = 0.01; // Für das Verlet verfahren

  // Hier werden die VErfahren mit den guten breiten durchgeführt. Bei Euler wird auch schon die Zeit gemessen

  auto start2 = high_resolution_clock::now();
  Euler(100, h_gut, y);
  auto stop2 = high_resolution_clock::now();
  Verlet(100, h_gut, x, v);



  ofstream file("source/output/ex_3_euler.txt");
  if (file.is_open()){
    file << "t_n" << "\t" << "x_1"  << "\t y_1"  << "\t x_2" << "\t y_2" << "\t v_x1" <<  "\t v_y1" << "\t v_x2" <<  "\t v_y2" << endl;
    for (int i = 0; i <= 100.0/h_gut; i++){
    file << h_gut * i <<"\t" << y[8 * i] << "\t" << y[1 + 8 * i] << "\t" << y[2 + 8 * i] << "\t" << y[3 + 8 * i] << "\t" << y[4 + 8 * i] << "\t" << y[5 + 8 * i] << "\t" << y[6 + 8 * i] << "\t" << y[7 + 8 * i] << endl;
    }
  }
  else{
  cout << "Unable to open file";
  }

  //Euler Rückwärts
  y = {y[8 * 100.0/h_gut], y[8 * 100.0/h_gut + 1], y[8 * 100.0/h_gut + 2], y[8 * 100.0/h_gut + 3], y[8 * 100.0/h_gut + 4], y[8 * 100.0/h_gut + 5], y[8 * 100.0/h_gut + 6], y[8 * 100.0/h_gut + 7]};
  Euler(100, -h_gut, y);

  
  ofstream eu_ruck("source/output/ex_3_euler_ruck.txt");
  if (eu_ruck.is_open()){
    eu_ruck << "t_n" << "\t" << "x_1"  << "\t y_1"  << "\t x_2" << "\t y_2" << "\t v_x1" <<  "\t v_y1" << "\t v_x2" <<  "\t v_y2" << endl;
    for (int i = 0; i <= 100.0/h_gut; i++){
    eu_ruck << h_gut * i <<"\t" << y[8 * i] << "\t" << y[1 + 8 * i] << "\t" << y[2 + 8 * i] << "\t" << y[3 + 8 * i] << "\t" << y[4 + 8 * i] << "\t" << y[5 + 8 * i] << "\t" << y[6 + 8 * i] << "\t" << y[7 + 8 * i] << endl;
    }
  }
  else{
  cout << "Unable to open file";
  }

  //Hier wird der Vektor resetet und dann das Euler VErfahren in Schlecht durchgeführt.

  y.clear();
  y = {0, 1, 0, -0.5, 0.8, 0, -0.4, 0};
  Euler(100, h_schlecht, y);
  
  ofstream file2("source/output/ex_3_euler_schl.txt");
  if (file2.is_open()){
    file2 << "t_n" << "\t" << "x_1"  << "\t y_1"  << "\t x_2" << "\t y_2" << "\t v_x1" <<  "\t v_y1" << "\t v_x2" <<  "\t v_y2" << endl;
    for (int i = 0; i <= 100.0/h_schlecht; i++){
    file2 << h_schlecht * i <<"\t" << y[8 * i] << "\t" << y[1 + 8 * i] << "\t" << y[2 + 8 * i] << "\t" << y[3 + 8 * i] << "\t" << y[4 + 8 * i] << "\t" << y[5 + 8 * i] << "\t" << y[6 + 8 * i] << "\t" << y[7 + 8 * i] << endl;
    }
  }
  else{
  cout << "Unable to open file";
  }

  ofstream file3("source/output/ex_3_verlet.txt");
  if (file3.is_open()){
    file3 << "t_n" << "\t" << "x_1"  << "\t y_1"  << "\t x_2" << "\t y_2" << "\t v_x1" <<  "\t v_y1" << "\t v_x2" <<  "\t v_y2" << endl;
    for (int i = 0; i < 100.0/h_gut-4; i++){
    file3 << h_gut * i <<"\t" << x[4 * i] << "\t" << x[1 + 4 * i] << "\t" << x[2 + 4 * i] << "\t" << x[3 + 4 * i] << "\t" << v[4 * i] << "\t" << v[1 + 4 * i] << "\t" << v[2 + 4 * i] << "\t" << v[3 + 4 * i] << endl;
    }
  }
  else{
  cout << "Unable to open file";
  }

  //Hier wird Verlet mit der schlechten Breite durchgeführt

  x.clear();
  v.clear();
  x = {0, 1, 0, -0.5};
  v = {0.8, 0, -0.4, 0};
  
 Verlet(100, h_schlecht, x, v);

   ofstream file4("source/output/ex_3_verlet_schl.txt");
  if (file4.is_open()){
    file4 << "t_n" << "\t" << "x_1"  << "\t y_1"  << "\t x_2" << "\t y_2" << "\t v_x1" <<  "\t v_y1" << "\t v_x2" <<  "\t v_y2" << endl;
    for (int i = 0; i < 100.0/h_schlecht-4; i++){
    file4 << h_schlecht * i <<"\t" << x[4 * i] << "\t" << x[1 + 4 * i] << "\t" << x[2 + 4 * i] << "\t" << x[3 + 4 * i] << "\t" << v[4 * i] << "\t" << v[1 + 4 * i] << "\t" << v[2 + 4 * i] << "\t" << v[3 + 4 * i] << endl;
    }
  }
  else{
  cout << "Unable to open file";
  }


  // Vertrauenswürdig für Verlet mit Zeitmessung
  x.clear();
  v.clear();
  x = {0, 1, 0, -0.5};
  v = {0.8, 0, -0.4, 0};
  


  auto start1 = high_resolution_clock::now();
  Verlet(100, h_vertrau, x, v);
  auto stop1 = high_resolution_clock::now();
  auto duration_verl = duration_cast<microseconds>(stop1 - start1);
  auto duration_euler = duration_cast<microseconds>(stop2 - start2);
  

   ofstream file5("source/output/ex_3_verlet_vertrau.txt");
  if (file5.is_open()){
    file5 << "t_n" << "\t" << "x_1"  << "\t y_1"  << "\t x_2" << "\t y_2" << "\t v_x1" <<  "\t v_y1" << "\t v_x2" <<  "\t v_y2" << endl;
    for (int i = 0; i <= 100.0/h_vertrau; i++){
    file5 << h_vertrau * i <<"\t" << x[4 * i] << "\t" << x[1 + 4 * i] << "\t" << x[2 + 4 * i] << "\t" << x[3 + 4 * i] << "\t" << v[4 * i] << "\t" << v[1 + 4 * i] << "\t" << v[2 + 4 * i] << "\t" << v[3 + 4 * i] << endl;
    }
  }
  else{
  cout << "Unable to open file";
  }

  // Hier kommt Verlet mit negativen Schrittbreiten
  
  x = {x[100.0/h_vertrau * 4], x[100.0/h_vertrau * 4 + 1], x[100.0/h_vertrau * 4 + 2], x[100.0/h_vertrau * 4 + 3]};
  v = {v[4 * 100.0/h_vertrau], v[4 * 100.0/h_vertrau + 1], v[4 * 100.0/h_vertrau + 2], v[4 * 100.0/h_vertrau + 3]};

  Verlet(100, -h_vertrau, x, v);

  ofstream Vruck("source/output/ex_3_verlet_rück.txt");
  if (Vruck.is_open()){
    Vruck << "t_n" << "\t" << "x_1"  << "\t y_1"  << "\t x_2" << "\t y_2" << "\t v_x1" <<  "\t v_y1" << "\t v_x2" <<  "\t v_y2" << endl;
    for (int i = 0; i <= 100.0/h_vertrau; i++){
    Vruck << h_vertrau * i <<"\t" << x[4 * i] << "\t" << x[1 + 4 * i] << "\t" << x[2 + 4 * i] << "\t" << x[3 + 4 * i] << "\t" << v[4 * i] << "\t" << v[1 + 4 * i] << "\t" << v[2 + 4 * i] << "\t" << v[3 + 4 * i] << endl;
    }
  }
  else{
  cout << "Unable to open file";
  }
  


    ofstream times("source/output/ex_3_times.txt");
  if (times.is_open()){
    times << "t_verlet" << "\t" << "t_Euler"  << "\t In Mikrosekunden"<< endl;
    times << duration_verl.count() << '\t' << duration_euler.count() << endl;
  }
  else{
  cout << "Unable to open file";
  }
  return 0;
}