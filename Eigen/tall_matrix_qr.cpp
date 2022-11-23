#include <iostream>

#include<Eigen/Dense>

using namespace Eigen;

int main() {
  Eigen::MatrixXd A = Eigen::MatrixXd::Random(5,3);

  Eigen::ColPivHouseholderQR<Eigen::MatrixXd> qr(5,3);
  qr.compute(A);

  Eigen::MatrixXd Q(qr.householderQ());
  Eigen::MatrixXd Rfull = qr.matrixR();
  Eigen::MatrixXd R = Rfull.template triangularView<Eigen::Upper>();

  std::cout << "householderQ\n" << Q << std::endl;
  std::cout << "Q'Q \n" << Q.transpose() * Q << std::endl;
  std::cout << "Rfull\n" << Rfull << std::endl;
  std::cout << "matrixR \n" << R << std::endl;
  std::cout << "matrixA \n" << A << std::endl;
  std::cout <<"QR\n" << Q*R << std::endl;

  return 0;
}
