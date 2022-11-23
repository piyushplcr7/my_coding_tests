#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int>& houses, int N, int k, vector<int> curr) {

  if (curr.size() == 0) {
    for (int i = 0 ; i < N ; ++i) {
      //cout << "starting values from position " << i << endl;
      vector<int> curry(curr);
      curry.push_back(i);
      dfs(houses,N,k,curry);
      //cout << "Finished tree from position " << i << endl;
    }
  }

  if (curr.size() > 0) {
    int last = curr.back();
    // Remaining mailboxes to allocate
    int rem = k-curr.size();

    if (rem > 0 && last < N-1) {
      for (int i = last+1 ; i < N ; ++i) {
        vector<int> curry(curr);
        curry.push_back(i);
        dfs(houses,N,k,curry);
      }
    }
    else {
      if (rem > 0 && last == N-1)
        return;
      if (rem == 0) {
        // Allocated all mailboxes, compute the distances
        vector<int> empty(N,0);
        for (auto el:curr)
          empty[el] = 1;
        for (auto el:empty)
          cout << el << " ";
        cout << endl;
        return;
      }
    }
  }

  return;
}

/*int minDistance(vector<int>& houses, int k) {

  }
*/
int main() {

  vector<int> houses = {1,2,4,9};
  int N = 3;
  int k = 1;

  vector<int> curr;

  dfs(houses,N,k,curr);

  return 0;
}
