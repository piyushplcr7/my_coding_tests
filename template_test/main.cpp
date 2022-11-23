#include <iostream>

double add_sol(double x, double y) {
	return x+y;
}

double add_stud(double x, double y) {
	return x+2*y;
}

template <typename ADD>
double test(double x, double y, ADD add) {
	return add(x,y);
}

int main() {
	double x = 1, y=2;
	std::cout << "stud: " << test(x,y,*add_stud) << std::endl;
	std::cout << "sol: " << test(x,y,*add_sol) << std::endl;
	return 0;
}
