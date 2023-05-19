#include <iostream>
#include <vector>
#include <Eigen/Dense>
//#include <random>
#include <fstream>
#include <string> 
#include <cmath>
#include <numbers>

using namespace std;
using namespace Eigen;




class Poisson
{
public:
    Poisson(Vector2d rand_h, Vector2d rand_v, double del, double kap, vector<Vector2d> qi, vector<double> q, double phi0);

    void save(const string &filenameSets, const string &Ex, const string &Ey);
    void iterate();
    void electric();
    void analytical(int f);

private: 
    double delt;
    double kappa;
    Vector2d rand_ho; //Horizontale und Vertikale Dirichlet --> 0 ist unten/links, 1 ist oben/rechts
    Vector2d rand_ve;
    Matrix2f ecken;

    void gauß_seidel_step();
    double phi0;
    MatrixXf phi;
    MatrixXf phivor; // für die Fehlergrenze
    MatrixXf electricx;
    MatrixXf electricy;
    uint N;
    MatrixXf calcRho(vector<Vector2d> qi, vector<double> q);
    MatrixXf rho;

    
};

Poisson::Poisson(Vector2d rand_h, Vector2d rand_v, double del, double kap, vector<Vector2d> qi, vector<double> q, double phi0):

  delt(del),
  rand_ho(rand_h),
  rand_ve(rand_v),
  kappa(kap),
  N(1/delt), //+1 fügt noch die Ränder hinzu
  ecken(ecken)
{
  phivor.resize(N,N);
  phi.resize(N,N);

  electricx.resize(N,N);
  electricx.setZero();
  electricy.resize(N,N);
  electricy.setZero();

  rho.resize(N,N);
  rho.setZero();

  rho = calcRho(qi, q);
  phi.setConstant(phi0);
  for(uint i = 0; i < N; i++)
  {
    phi(0,i)   = rand_ve[0];
    phi(N-1,i) = rand_ve[1];
    phi(i,0)   = rand_ho[0];
    phi(i,N-1) = rand_ho[1];
  }

}

void Poisson::analytical(int f)
{
  phi.setZero();
  vector<double> x, y;
  for(int i = 0; i < N; i++){
    x.push_back(i * delt);
    y.push_back(i * delt);
  }
  for(int n = 1; n < f; n++){
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        phi(j,i) += 2*(1-cos(n * numbers::pi))/(n * numbers::pi * sinh(n * numbers::pi)) * sin(n * numbers::pi * x[i]) * sinh(n * numbers::pi * y[j]);
      }
    }
  }
  electric();
}

void Poisson::iterate()
{

  cout << "Gauß Seidel ist der Übeltäter" << endl;
  
  for(uint i = 0; i < 1e3; i++) //Lieber mal irgendeinen Abbruch falls was nicht läuft
  {
    gauß_seidel_step();
    MatrixXf Fehler(N,N);
        Fehler = phi - phivor;
        double min = Fehler.minCoeff()*(-1);
        double max = Fehler.maxCoeff();
        if(min < max)
        {
          if(abs(max) < kappa)
          {
            electric();
            return;}
        }
        else{
          if(abs(min) < kappa)
          {
            electric();
            return;
          }
        }
  }
}

void Poisson::gauß_seidel_step()
{ 
  //einmal alle Gitterplätze durchgehen
  Matrix2f temp;
  temp.setZero();
  phivor = phi;
  for(uint l = 1; l < N-1; l++){
    for(uint j = 1; j < N-1; j++){
      temp(0,0) = phi(j-1, l);
      temp(1,0) = phi(j+1, l);
      temp(0,1) = phi(j, l+1);
      temp(1,1) = phi(j, l-1);
      
      phi(j,l) = 1./4 * (temp(0,0) + temp(1,0) + temp(0,1) + temp(1,1)) + 1./4 * delt * delt * rho(j,l);
    }
  }
  

    //|phi(n+1) - phi(n)| < kap
  }
void Poisson::save(const string &filenameSets, const string &Ex, const string &Ey)
{
  ofstream myfile;

    // save datasets
    myfile.open(filenameSets);
    myfile << phi  << "\t"  << endl;
    myfile.close();

    myfile.open(Ex);
    myfile << electricx << "\t"  << endl;
    myfile.close();

    myfile.open(Ey);
    myfile << electricy << "\t"  << endl;
    myfile.close();
}

void Poisson::electric()
{
  cout << "Hier falsch" << endl;
  //Ränder mit Diffquo
  for(uint i = 0; i < N; i++){
    electricx(0,i)    = - (phi(1,i)    - phi(0,i))/delt;
    electricx(N-1,i)  = - (phi(N-1,i)  - phi(N-2,i))/delt;
    electricy(i, 0)   = - (phi(i,1)    - phi(i,0))/delt;
    electricy(i, N-1) = - (phi(i, N-1) - phi(i, N-2))/delt;
  }
  //Innen mit 2 sympunkt
  for(uint i = 1; i < N-1; i++){
    for(uint j = 1; j < N-1; j++){
      electricx(i,j) = - (phi(i+1, j) - phi(i-1, j)) * 1./(2*delt);
      electricy(i,j) = - (phi(i, j+1) - phi(i, j-1)) * 1./(2*delt);
    }
  }
}

MatrixXf Poisson::calcRho(vector<Vector2d> qi, vector<double> q)//Funktioniert
{
  MatrixXf rho(N,N);
  if(qi.size() == 0)
  {
    
  }else
  {
    for(uint i = 0; i < qi.size(); i++){
      uint n = qi.at(i)(0) / delt;
      uint k = qi.at(i)(1) / delt;
      rho(n,k) += q[i];
    }
  }
  return rho;
}






int main(void)
{
  //Randbedingungen
  Vector2d rand_h(0,0);
  Vector2d rand_v(0,0);

  //Für Rho
  Vector2d tempa(0,0); //Teilchenort
  vector<Vector2d> qi;
  qi.push_back(tempa);

  vector<double> q; //Teilchenladung
  q.push_back(0);

  string Tstring = "Aufgabe1";

  //b)
  Poisson a(rand_h, rand_v, 0.05, 1e-5, qi, q, 1);
  a.iterate();
  a.save("source/output/a)set" + Tstring + ".dat", "source/output/Ex_b.dat", "source/output/Ey_b.dat");


  //c)
  Vector2d randvc(0,1);

  Poisson c(rand_h, randvc, 0.05, 1e-5, qi, q, 1);
  c.iterate();
  c.save("source/output/c)set" + Tstring + ".dat", "source/output/Ex_c.dat", "source/output/Ex_c2.dat");
  
  int n = 200;
  Poisson ca(rand_h, randvc, 0.05, 1e-5, qi, q, 1);
  ca.analytical(n);
  ca.save("source/output/can)set" + Tstring + ".dat", "source/output/c3.dat", "source/output/c4.dat");
  


  //d)
    //Für Rho
  Vector2d tempd(0.5,0.5); //Teilchenort
  vector<Vector2d> qid;
  qid.push_back(tempd);

  vector<double> qd; //Teilchenladung
  qd.push_back(+1);


  Poisson d(rand_h, rand_v, 0.05, 1e-5, qid, qd, 1);
  d.iterate();
  d.save("source/output/d)set" + Tstring + ".dat", "source/output/Ex_d.dat", "source/output/Ey_d.dat");

  //e)
  vector<double> qe; //Teilchenladung
  vector<Vector2d> qie;

  Vector2d tempe(0.25,0.25); //Teilchen 1
  qie.push_back(tempe);
  qe.push_back(+1);

  tempe = {0.75, 0.75};
  qie.push_back(tempe);
  qe.push_back(+1);

  tempe = {0.25, 0.75};
  qie.push_back(tempe);
  qe.push_back(-1);

  tempe = {0.75, 0.25};
  qie.push_back(tempe);
  qe.push_back(-1);




  Poisson e(rand_h, rand_v, 0.05, 1e-5, qie, qe, 1);
  e.iterate();
  e.save("source/output/e)set" + Tstring + ".dat", "source/output/Ex_e.dat", "source/output/Ey_e.dat");

  return 0;
}