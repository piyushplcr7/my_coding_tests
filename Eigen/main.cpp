#include <iostream>
#include <Eigen/Dense>

int main(){
	Eigen::VectorXd v = Eigen::VectorXd::Random(10);
	std::cout << "Vector v full \n" << v << std::endl;
	std::cout << "Vector head(5) \n" << v.head(5) << std::endl;
	return 0;
}
