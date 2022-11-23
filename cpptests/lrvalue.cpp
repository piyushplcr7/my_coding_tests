#include <iostream>
#include <Eigen/Dense>

Eigen::VectorXd myfun() {
	Eigen::VectorXd ret = Eigen::VectorXd::Constant(5,5);
	return ret;
}

double sumvec(Eigen::VectorXd&& x) {
	return x.array().sum();
}

int main() {
	std::cout << "check " << sumvec(myfun()) << std::endl;
	return 0;
	
}
