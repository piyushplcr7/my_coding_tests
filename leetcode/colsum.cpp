#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int N = colsum.size();
        int u = upper;
        int l = lower;
        vector<vector<int>> out(2,vector<int> (N,0));
        vector<vector<int>> empty(2,vector<int> (N,0));
        vector<int> mark;
        for (int i = 0 ; i < N ; ++i) {
            //if (colsum[i] > 0 && l == 0 && u == 0)
            //    return empty;
            if (colsum[i] == 2) {
                out[0][i] = 1;
                out[1][i] = 1;
                u--;
                l--;
            }

            if (colsum[i] == 1) {
                if (u > l) {
                    //mark.push_back(i);
                    out[0][i] = 1;
                    out[1][i] = 0;
                    u--;
                }
                else {
                    out[0][i] = 0;
                    out[1][i] = 1;
                    l--;
                }
            }
        }
        int usum = 0;
        int lsum = 0;
        for (int x:out[0])
            usum += x;
        for (int x:out[1])
            lsum += x;
        cout << "computed usum = " << usum << ", lsum = " << lsum << std::endl;
        if (lsum!=lower || usum != upper)
            return empty;
        return out;
    }
};

int main() {
  Solution obj;
  vector<int> test = {2,2,1,1};

  vector<vector<int>> out = obj.reconstructMatrix(2,3,test);
  for (int x:out[0])
    std::cout << x << ",";
  std::cout << std::endl;
  for (int x:out[1])
    std::cout << x << ",";
  std::cout << std::endl;
}
