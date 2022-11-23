#include <iostream>
#include <functional>

int main() {
int c = 2;
int (*lol)(int,int) multiply = (int a,int b)->{
	int out = a*b;
	return out;
};

std::cout << multiply(3,4) << std::endl;
return 0;
}
