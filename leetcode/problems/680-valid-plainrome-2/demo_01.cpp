#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    bool validPalindrome(string s) {
        return valid_palindrome(s);
    }
    bool valid_palindrome(const string &s) {

        if (s.size() == 1) return true;

        int begin = 0;
        int rbegin = s.size() - 1;

        while (begin < rbegin) {
            if (s[begin] == s[rbegin]) {
                ++begin;
                --rbegin;
                continue;
            } else {
                bool left_ok = true;
                bool right_ok = true;
                int sub_begin = begin + 1;
                int sub_rbegin = rbegin;
                while (sub_begin < sub_rbegin) {
                    if (s[sub_begin] != s[sub_rbegin]) {
                        left_ok = false;
                        break;
                    }
                    ++sub_begin;
                    --sub_rbegin;
                }
                sub_begin = begin;
                sub_rbegin = rbegin - 1;
                while (sub_begin < sub_rbegin) {
                    if (s[sub_begin] != s[sub_rbegin]) {
                        right_ok = false;
                        break;
                    }
                    ++sub_begin;
                    --sub_rbegin;
                }
                return left_ok || right_ok;
            }
        }
        return true;
    }
};

int main(int argc, char* argv[]) 
{
    Solution s;
    std::string plain_list[]{"a","aa" , "ab", "abc", "abba", "abdba", "deee",
            "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga"};
    for (auto &x : plain_list ) {
        bool ok = s.validPalindrome(x);
        std::cout<<"`" << x << "`: " <<ok <<std::endl;

    }
    return 0;
}
