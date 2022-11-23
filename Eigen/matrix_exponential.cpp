#include<iostream>
#include <unsupported/Eigen/MatrixFunctions>

Eigen::MatrixXd phim(const Eigen::MatrixXd &Z) {
  int n = Z.cols();
  assert(n == Z.rows() && "Matrix must be square.");
  Eigen::MatrixXd C(2 * n, 2 * n);
  C << Z, Eigen::MatrixXd::Identity(n, n), Eigen::MatrixXd::Zero(n, 2 * n);
  return C.exp().block(0, n, n, n);
}

Eigen::MatrixXd my_phim(const Eigen::MatrixXd &Z) {
  int n = Z.cols();
  assert(n == Z.rows() && "Matrix must be square.");
  Eigen::MatrixXd expZ = Z.exp();

  Eigen::MatrixXd phi = (expZ-Eigen::MatrixXd::Identity(n,n));
  phi *= Z.inverse();
  return phi;
}

int main() {
  Eigen::Matrix2d testZ = Eigen::MatrixXd::Random(2,2);
  auto phi1 = phim(testZ);
  auto phi2 = my_phim(testZ);

  std::cout << "phi oliver \n" << phi1 << std::endl;

  std::cout << "phi my \n" << phi2 << std::endl;

  return 0;
}
