#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
//#include <numbers>
#include <Eigen/Dense>
#include <Eigen/Core>


using namespace std;
using namespace Eigen;


uint sigma = 10;
double b = 8. / 3;


Vector3d f(Vector3d Y, double r){
    Vector3d Y2;
    //cout << endl << "in funktion: "<<endl<< Y << endl << Y(0) << endl;
    Y2(0) = sigma * Y(1) - sigma * Y(0);
    Y2(1) = - Y(0) * Y(2) + r * Y(0) - Y(1);
    Y2(2) = Y(0) * Y(1) - b * Y(2);

    return Y2;
}


Vector3d RungeKutter(Vector3d Y, double r, Vector3d (*f)(Vector3d, double), double h){
    Vector3d k1 = h * f(Y, r);
    Vector3d k2 = h * f(Y + k1/2., r);
    Vector3d k3 = h * f(Y + k2/2., r);
    Vector3d k4 = h * f(Y + k3, r);

    Vector3d Yn2 = Y + 1/6. * (k1 + 2 * k2 + 2 * k3 + k4);
    //cout << endl <<Yn2 << endl;

    return Yn2;
}


int main(){
    double h = 1e-3;
    uint N = 1e5;
    double r1 = 20;
    double r2 = 28;

    Vector3d Y0;
    

    //cout << Y0 << endl;

    vector<Vector3d> Y1;
    vector<Vector3d> Y2;
    
    string xwerte[3] = {"1", "23", "32"};
    for(auto& xwert: xwerte)
    {

    Y1.clear();
    Y2.clear();
    Y0 << stod(xwert), 17, 13;
    Y1.push_back(Y0);
    Y2.push_back(Y0);

    //cout << f(Y1.at(0), r1) << endl;
    ofstream pr20;
    ofstream pr28;
    pr20.open("source/output/pr20_" + xwert + ".txt");
    pr28.open("source/output/pr28_" + xwert + ".txt");


    for(uint i = 0; i < N; i++){

        double t = i * h;

        Vector3d Yn1 =  RungeKutter(Y1.at(i), r1, f, h);
        Vector3d Yn2 =  RungeKutter(Y2.at(i), r2, f, h);

        Y1.push_back(Yn1);
        Y2.push_back(Yn2);
        if(i % 5 == 1){
            pr20 << Y1.at(i)(0) <<  ", " << Y1.at(i)(1) <<  ", " << Y1.at(i)(2) << endl;
        }
        if(i % 10 == 1){
            pr28 << Y2.at(i)(0) <<  ", " << Y2.at(i)(1) <<  ", " << Y2.at(i)(2)<< endl;
        }

    }
      
    pr20.close();
    pr28.close();
    }
    ofstream z20_20;
    z20_20.open("source/output/z20_20.txt");

    for( uint i = 0; i < Y1.size()-1; i++){
        if(i % 1000 == 0){cout << i/1000. << endl;}

        if(Y1.at(i)(2) >= 20){
             if(Y1.at(i+1)(2) <= 20){
                 double a = Y1.at(i)(2) - 20;
                 double b = 20 - Y1.at(i+1)(2);
                 cout << i << endl;
                 z20_20 << (b * Y1.at(i)(0) + a * Y1.at(i+1)(0)) / (a + b) <<  ", " << (b * Y1.at(i)(1) + a * Y1.at(i+1)(1)) / (a + b) << endl;
             }
        }
    }
    z20_20.close();

    ofstream z20_28;
    z20_28.open("source/output/z20_28.txt");

    for( uint i = 0; i < Y2.size()-1; i++){
        
        if(Y2.at(i)(2) >= 20){
            if(Y2.at(i+1)(2) <= 20){
                double a = Y2.at(i)(2) - 20;
                double b = 20 - Y2.at(i+1)(2);
                z20_28 << (b * Y2.at(i)(0) + a * Y2.at(i+1)(0)) / (a + b) <<  ", " << (b * Y2.at(i)(1) + a * Y2.at(i+1)(1)) / (a + b) << endl;
            }
        }
        
    }
    z20_28.close();


    return 0;
}