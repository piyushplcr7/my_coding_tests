#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        int kase = -1; // 0 for clean line, 1 for // , 2 for /*, 3 for */
        vector<string> output;
        int pos = -1;
        int Nlines = source.size();
        // Line number and character number
        std::pair<int,int> blockstart;
        std::pair<int,int> blockend;
        for (int l = 0 ; l < Nlines ; ++l) {
            // Searching the line for comment characters
            string line = source[l];
            int linesize = line.size();
            std::cout << "Searching line " << l << " = " << line << std::endl;
            for (int i = 0 ; i < linesize-1 ; ++i ) {
                if  (line[i] =='/' && line[i+1] == '/' && kase !=2) {
                    kase = 1;
                    pos = i;
                    break;
                }
                if  (line[i] =='/' && line[i+1] == '*') {
                    kase = 2;
                    blockstart.first = l;
                    blockstart.second = i;
                    std::cout << "Found block comment start at " << l << ", " << i << std::endl;
                    //break;
                }
                if  (line[i] =='*' && line[i+1] == '/') {
                    kase = 3;
                    blockend.first = l;
                    blockend.second = i+2;
                    std::cout << "Found block comment end at " << l << ", " << i << std::endl;
                    break;
                }
                //kase = 0;
            }

            // Processing line based on kase
            if (kase == 0)
                output.push_back(line);
            if (kase == 1) {
                if (pos == 0) {}
                else {
                    output.push_back(line.substr(0,pos));
                }
                kase = 0;
            }
            if (kase == 3) {
                // Need to delete the block comment
                std::cout << "Deleting block comment " << blockstart.first << "," << blockstart.second << " to " << blockend.first << "," << blockend.second << std::endl;
                string firstpart = source[blockstart.first].substr(0,blockstart.second);
                string secondpart = source[blockend.first].substr(blockend.second,source[blockend.first].size());
                string joined = firstpart+secondpart;
                std::cout << "firstpart = " << firstpart << std::endl;
                std::cout << "secondpart = " << secondpart << std::endl;
                if (joined.size() >0)
                    output.push_back(joined);
                kase = 0;
            }

        }
        return output;
    }
};

int main() {
  Solution obj;
  vector<string> input = {"/*Test program */", "int main()", "{ ", "int k; // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"};
  //vector<string> input = {"int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"};
  std::cout << "Input =====" << std::endl;
  for (auto el : input) {
    std::cout << el << std::endl;
  }
  vector<string> out = obj.removeComments(input);
  std::cout << "Output =====" << std::endl;
  for (auto el : out ) {
    std::cout << el << std::endl;
  }
  return 0;
}
