#include<iostream>
#include<Eigen/Dense>

int main() {
Eigen::MatrixXd A = Eigen::MatrixXd::Constant(3,4,1);
std::cout << A.colwise().sum() << std::endl;

return 0;}
