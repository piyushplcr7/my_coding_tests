#include<iostream>
#include<vector>

using namespace std;

int main() {
  //vector<int> x(2,3);
  vector<int> x = vector<int> (2,3);

  vector<vector<int>> (6,vector<int> (3));

  for (int el:x)
    std::cout << el << " " << std::endl;
  return 0;
}
