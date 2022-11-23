#include <iostream>
#include "h1.hpp"
#include <vector>

int main() {
	std::vector<int> v(2);
	v.push_back(786);
	v.push_back(666);
	foo(v);
	return 0;
}
