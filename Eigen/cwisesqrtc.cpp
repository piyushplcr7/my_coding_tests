#include<iostream>
#include<Eigen/Dense>

int main() {
	Eigen::VectorXd v(3);
	v << 4,9,16;
	v.cwiseSqrt();
	std::cout << "v "<< v << std::endl;
	v = v.cwiseSqrt();
	std::cout << "v "<< v << std::endl;
	//std::cout << v.cwiseSqrt() << std::endl;
	return 0;
}
