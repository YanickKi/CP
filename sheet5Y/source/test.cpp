#include </home/yanick/.include/Eigen/Dense>
#include <iostream>
using namespace std;

const int D = 50;

int main(){
    //Eigen::MatrixXd H = Eigen::ArrayXf::LinSpaced(1, 1, D) * Eigen::ArrayXf::LinSpaced(1, 1, qD).transpose();
    Eigen::MatrixXf H = Eigen::VectorXf::LinSpaced(D, 1, D) * Eigen::VectorXf::LinSpaced(D, 1, D).transpose();
    //for(int i = 0; i < D; i++){
    //    for(int j = 0; j < D; j++){
    //        cout << H(j,i) << "\t";
    //    }
    //    cout << endl;
    //}
    cout << H;
    return 0;
}