#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
    int longestBeautifulSubstring(string word) {
        vector<char> condensed_chars(1,0);
        vector<int> multiplier(1,0);
        unsigned size = 0;
        char prev_char = 'z';
        std::cout << "check" << std::endl;
        for (auto c : word) {
        std::cout << "reached character " << c << std::endl;
            if (c == prev_char) {
            std::cout << "check" << std::endl;
                multiplier[size-1] += 1;
            }
            else {
            
                size += 1;
                condensed_chars.push_back(c);
                std::cout << "check" << std::endl;
                multiplier[size-1] += 1;   
                std::cout << "check" << std::endl;
                         }
        }
       
        unsigned N = word.size();
        unsigned answer = 0;
        for (unsigned i = 0 ; i < N-5 ; ++i) {
            if (word[i]=='a' && word[i+1]=='e' && word[i+2]=='i' && word[i+3]=='o' && word[i+4]=='u' ) {
                int sum = multiplier[i]+multiplier[i+1]+multiplier[i+2]+multiplier[i+3]+multiplier[i+4];
                answer = answer > sum? answer : sum;
            }
               
        }
       return answer;
    }
};


int main() {
	string word = "aeiou";
	Solution obj;
	
	int out = obj.longestBeautifulSubstring(word);
	
	std::cout << "out" << std::endl;
	return 0;
	

}
