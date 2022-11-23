#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<tuple>

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



// Evaluate the string. idx 0 means sum 1 means minus and 2 means product
int evaluate(vector<int> idx, vector<int> num) {
    int N = num.size();

    // Collapsing products
    for (int i = 0 ; i < N-1 ; ++i) {
        if (idx[i] == 2) {
            num[i+1] = num[i]*num[i+1];
            num[i] = 0;
            if (i==0)
              idx[i] = 0;
            else
              idx[i] = idx[i-1];
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

string create_string1(vector<int> num, vector<int> idx) {
    int N = num.size();
    string news;
    string ops = "+-*";

    for (int i = 0 ; i < N-1 ; ++i) {
        news+=to_string(num[i]);
        news.push_back(ops[idx[i]]);
    }
    news += to_string(num[N-1]);
    return news;
}



pair<vector<int>,vector<int>> collapse(string num, vector<int> idx) {
  vector<string> collapsed_nums;
  vector<int> collapsed_ops;
  int N = num.size();
  int cnt = 0;
  collapsed_nums.push_back( string (1,num[0]));
  for (int i = 0 ; i < N-1 ; ++i ) {
    if (idx[i] != 3) {
      cnt++;
      collapsed_nums.push_back(string (1,num[i+1]) );
      collapsed_ops.push_back(idx[i]);
    }
    else {
      collapsed_nums[cnt] += num[i+1];
    }
  }
  vector<int> col_num_int;
  for (auto str:collapsed_nums)
    col_num_int.push_back(stoi(str));
  return std::make_pair(col_num_int,collapsed_ops);
}

bool check(string test, string num) {
  int N = num.size();
  int cnt = 0;
  for (auto el:test)
    if ((int) el - (int) '0' >=0 && (int) el - (int) '0' <=9 )
      cnt++;
  return N==cnt;
}

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        int N = num.size();
        vector<string> out;
        vector<int> num_int;

        // Converting to array of integers for easy evaluation
        for (char el:num)
            num_int.push_back((int) (el-'0'));


        // Creating operator string combinations
        vector<int> idx(N-1,0);

        for (int i = 0 ; i < std::pow(4,N-1) ; ++i) {
          // Collapsing numbers
          vector<int> collapsed_numbers;
          vector<int> collapsed_idx;
          std::tie(collapsed_numbers,collapsed_idx) = collapse(num,idx);

          /*std::cout << "attempt " << i << std::endl;

          cout << "Number sequence = " << endl;
          for (auto el:collapsed_numbers)
            std::cout << el << " " ;

          cout << endl;

          cout << "Op sequence = " << endl;
          for (auto el:idx)
            std::cout << el << " " ;

          cout << endl;

          cout << "Collapsed Op sequence = " << endl;
          for (auto el:collapsed_idx)
            std::cout << el << " " ;

          cout << endl;*/

          int eval = evaluate(collapsed_idx,collapsed_numbers);
            if (eval == target) {
              string possible = create_string1(collapsed_numbers,collapsed_idx);
              if (check(possible,num))
                out.push_back(possible);
            }


            //std::cout << create_string1(collapsed_numbers,collapsed_idx) << " = " << evaluate(collapsed_idx,collapsed_numbers) << std::endl;
            idx = advance(idx,4);

        }

        return out;
    }
};

int main() {
  Solution obj;

  string num = "3456237490";
  //std::cin >> num;
  int target = 9191;
  //std::cin >> target;

  vector<string> sol = obj.addOperators(num,target);
  std::cout << "computed sol size = " << sol.size() << std::endl;
   for (string str:sol)
    std::cout << str << std::endl;
  //vector<int> numm = {2,3,2};
  //vector<int> ops = {1,2};

  //int  test = evaluate(ops,numm);
  //std::cout << create_string(num,ops) << " = " << test << std::endl;

  /*string num = "12345";
  vector<int> idx = {3,0,1,2}; // Represents the operation 12+3-4*5

  vector<int> col_num,col_idx;

  std::tie(col_num,col_idx) = collapse(num,idx);

  cout << "print nums" << std::endl;
  for (auto el:col_num)
  std::cout << el << " " ;
  cout << endl;
  cout << "print idx" << std::endl;
  for (auto el:col_idx)
  std::cout << el << " " ;*/

  return 0;
}
