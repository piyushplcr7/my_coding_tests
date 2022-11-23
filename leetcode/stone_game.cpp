#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
      vector<int> threekp1;
      vector<int> threekp2;
      vector<int> threek;
      for (auto el:stones) {
        if (el % 3 == 0)
          threek.push_back(el);
        if (el % 3 == 1)
          threekp1.push_back(el);
        if (el % 3 == 2)
          threekp2.push_back(el);
      }
      int N3k = threek.size();
      int N3kp1 = threekp1.size();
      int N3kp2 = threekp2.size();
      int N = stones.size();
      
    }
};

int main() {

  return 0;
}
