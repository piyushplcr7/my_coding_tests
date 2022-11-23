#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> advance(vector<int> number,int base) {
    vector<int> advno(number);
    int N = number.size();
    int carry = 1;

    for (int i = N-1; i >= 0 ; --i) {
        if (advno[i]+carry >= base ) {
            advno[i] = (advno[i]+carry)%base;
            carry = 1;
        }
        else {
          advno[i] += carry;
          carry = 0;
        }

    }
    return advno;
}

void printnum(vector<int> num) {
  for (auto el:num)
    std::cout << el;
  std::cout << std::endl;
}

int evaluate(vector<int> idx, vector<int> num) {
    int N = num.size();

    for (int i = 0 ; i < N-1 ; ++i) {
        if (idx[i] == 2) {
            num[i] = num[i]*num[i+1];
            num[i+1] = 0;
            idx[i] = 0;
        }
    }
    int sum = num[0];
    for (int i = 0 ; i < N-1 ; ++i)
        sum = sum + (- 2 * idx[i] + 1) * num[i+1];

    return sum;
}

string create_string(string num, vector<int> idx) {
    int N = num.size();
    string news;
    string ops = "+-*";

    for (int i = 0 ; i < N-1 ; ++i) {
        news.push_back(num[i]);
        news.push_back(ops[idx[i]]);
    }
    news.push_back(num[N-1]);
    return news;
}

int main() {
  /*vector<int> num(5,0);
  for (int i = 0 ; i < 32 ; ++i) {
    printnum(num);
    num = advance(num,2);
  }*/

  vector<int> num = {1,2,3,4,5};
  // Trying to evaluate the expression 1-2+3*4-5 = 6
  vector<int> idx = {1,0,2,1};


  std::cout << evaluate(idx,num) << std::endl;

  std::string numm = "12345";
  std::cout << create_string(numm,idx) << std::endl;
  int N = numm.size();

        vector<int> num_int;

        for (char el:numm)
            num_int.push_back((int) (el-'0'));
  for (int el:num_int)
    std::cout << el;

  return 0;
}
