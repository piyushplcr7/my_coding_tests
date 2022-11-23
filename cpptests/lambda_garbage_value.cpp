#include<iostream>
#include<Eigen/Dense>
#include<functional>

int main() {

double alpha1 = 3.0;
  double alpha2 = 2.0;
  double beta1 = 0.1;
  double beta2 = 0.1;
  
  /*
    auto Df = [&](const Eigen::Vector2d &y, const Eigen::Vector2d &z) {
    Eigen::Matrix2d Df;
    Df << alpha1 - beta1 * y(1), -beta1 * y(0), beta2 * y(1),
        -alpha2 + beta2 * y(0);
        //std::cout << "input y = " << y.transpose() << ", input z = " << z.transpose() << std::endl;
        std::cout << "Df * z inside lambda = " << Df * z << std::endl;
    return Df * z;
  };*/ //Returns garbage
  
  /*std::function<Eigen::Vector2d(const Eigen::Vector2d&,const Eigen::Vector2d&)> Dff = [&](const Eigen::Vector2d &y, const Eigen::Vector2d &z) {
    Eigen::Matrix2d Df;
    Df << alpha1 - beta1 * y(1), -beta1 * y(0), beta2 * y(1),
        -alpha2 + beta2 * y(0);
        //std::cout << "input y = " << y.transpose() << ", input z = " << z.transpose() << std::endl;
        std::cout << "Df * z inside lambda = " << Df * z << std::endl;
    return Df * z;
  };*/ // Throws even more garbage
  
  std::function<Eigen::Vector2d(const Eigen::Vector2d&,const Eigen::Vector2d&)> Dff = [&](const Eigen::Vector2d &y, const Eigen::Vector2d &z) {
    Eigen::Matrix2d Df;
    Df << alpha1 - beta1 * y(1), -beta1 * y(0), beta2 * y(1),
        -alpha2 + beta2 * y(0);
        //std::cout << "input y = " << y.transpose() << ", input z = " << z.transpose() << std::endl;
        std::cout << "Df * z inside lambda = " << Df * z << std::endl;
    Eigen::Vector2d out = Df*z;    
    return out;
	//return Df*z;  
  };
  
  Eigen::Vector2d y(100,5);
  Eigen::Vector2d z(10,10);
  
  auto val = Dff(y,z);
  
  std::cout << "Dff(y,z) = " << val << std::endl;

return 0;
}
