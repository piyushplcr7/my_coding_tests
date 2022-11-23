#include <iostream>
#include <Eigen/Dense>
#include <string>

double polyeval(const Eigen::VectorXd &t, const Eigen::VectorXd& y, double x) {
  int n = y.size();
  double out = 0;
  for (int i = 0; i < n ; ++i) {
    double pdt=1;
    // Evaluating the ith Lagrangian polynomial, which is 1 at t[i] and 0 at other pts
    for (int j = 0 ; j < n ; ++j) {
      if (i!=j)
        pdt *= (x-t(j))/(t(i)-t(j));
    }
    out += pdt * y(i);
  }
  return out;
}

double aitkeneville(const Eigen::VectorXd &t, const Eigen::VectorXd& y, double x) {
  int n = y.size();
  double out = 0;

}

int main( ) {
  Eigen::VectorXd t(4),y(4);
  t << 0, 1, 2, 3;
  y << 0, 1, 8, 27;
  // A cubic polynomial fits 4 points exactly

  double x;
  char inp;

  std::cin >> x;

  while ( x != (int) '\n') {
    std::cout << "polyeval(" << x << ") = " << polyeval(t,y,x) << std::endl;
    std::cout << "reference value: x^3 = " <<   x*x*x << std::endl;
    std::cin >> x;
  }


  return 0;
}
