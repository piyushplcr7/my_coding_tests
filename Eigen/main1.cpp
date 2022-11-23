#include <iostream>
#include <Eigen/Dense>
#include <string>

#include "eval_deriv.hpp"

int main( ) {
  Eigen::VectorXd t(4),y(4);
  t << 0, 1, 2, 3;
  y << 0, 1, 8, 27;
  // A cubic polynomial fits 4 points exactly

  double x;
  char inp;

  std::cin >> x;

  while ( x != (int) '\n') {
    Eigen::VectorXd X(1);
    X << x;
    std::cout << "polyeval(" << x << ") = " << dipoleval(t,y,X) << std::endl;
    std::cout << "reference value: x^3 = " <<   x*x*x << std::endl;
    std::cin >> x;
  }


  return 0;
}
