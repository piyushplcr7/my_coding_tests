#include<iostream>
#include<Eigen/Dense>

int main() {
	Eigen::MatrixXd X = Eigen::MatrixXd::Random(4,4);
	Eigen::MatrixXd R = X.template triangularView<Eigen::Lower>();
	std::cout << R << std::endl;
	return 0;
}
