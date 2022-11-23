#include <iostream>

#include <vector>

std::vector<int> just_bigger(std::vector<int>& v) {
  std::vector<int> out(v);
  unsigned count =0;

  for (std::vector<int>::iterator it = out.end() ; it >= out.begin() ; --it) {
    if (it != v.begin()) {
      if (*it == 1 && *(it-1) == 0) {
        *it = 0;
        *(it-1) = 1;
        break;
      }
    }
  }
  return out;
}

void print_vector(std::vector<int>& v) {
  for (auto el:v)
    std::cout << el << " ";
  std::cout << std::endl;
}

int main() {
  int N = 10;
  int r = 3;
  std::cout << "generating "<< N << "C_" << r << " combinatorial possibilities" << std::endl;

  std::vector<int> v(N,0);

  for (int i = 0 ; i < r ; ++i) {
    v[N-1-i] = 1;
  }
  std::vector<int> vin = v;

  for (int i = 0; i < 50 ; ++i) {
    print_vector(vin);
    std::vector<int> vout = just_bigger(vin);
    vin = vout;
  }

  // IDEA: THINK OF COLLISION OF THE BLOCKS OF 1s as you push them left.
  // IF THE BLOCKS are coagulated, it splits into two parts with one 1 to the left and the rest of the block toi the right
  
}
