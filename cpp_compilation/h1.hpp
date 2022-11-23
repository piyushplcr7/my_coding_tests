#ifndef H1HPP
#define H1HPP

#include <vector>
#include <iostream>

void foo(const std::vector<int>& v, double atol, double rtol) {
	for (auto x : v) {
		std::cout << x << std::endl;
	}
	
	std::cout << "atol = " << atol << std::endl;
	std::cout << "rtol = " << rtol << std::endl;
}

#endif
