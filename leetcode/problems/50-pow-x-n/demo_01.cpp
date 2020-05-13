#include <iostream>


class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (x == 1.0) return  1;
        
        unsigned long long u_n = n;
        if (n < 0) {
            x = 1/x;
            u_n = std::abs(n);
        }
        double final_value = 1;
        while (u_n) {
            if (u_n & 1) final_value *= x;

            x *= x;
            u_n >>= 1;
        } 
        return final_value;
    }
};

int main(int argc, char* argv) 
{
    return 0;
}
