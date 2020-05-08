#include <iostream>
#include <vector>

class Solution {
public:
    bool isPalindrome(int x) {
        // nagtive numbers never satisfy
        if (x < 0) return false;
        // if last digit of x(x > 0) equals 0 then never satisfy
        if (x > 0 && (0 == x % 10)) return false;
        int reverse = 0;
        int rest    = 0;
        // just compare (half of x) 
        rest = x;
        while (rest > reverse) {
            reverse = reverse * 10 +  (rest % 10);
            rest = rest / 10;
        }
        
        if (rest == reverse) return true;
        if (rest == reverse / 10) return true;
        return false;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> numbers { -121, -11, -10, -1, 0, 1, 22, 12321, 121 , 144444441};
    Solution s;
    for (auto & n : numbers) {
        std::cout<< n <<" is palindrom number ? " <<s.isPalindrome(n)  <<std::endl;
    }
    return 0;
}
