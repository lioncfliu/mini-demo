#include <iostream>
#include <cmath>
ass Solution {
public:
    int mySqrt(int x) {
        if (x <= 0) return 0;
        if (x == 1) return 1;
        return sqrt_inv(x);
    }
    int sqrt_binary_section(int n) {
        if (n < 0) return 0;
        int left = 0;
        int right = n;
        int mid = 0;
        while (left < right) {
            mid = (left + right + 1) >> 1;

            //long long square = mid * mid; // may overflow
            if (long(mid * mid) > n) right = mid - 1;
            else left = mid;

        }

        return left;
    }

    double sqrt_newton(int n) {
        if (n < 0) return 0.0f;

        double last = 0.0f;
        double final_value = n;
        while(true) {
            final_value = (final_value + n / final_value) / 2;
            if (std::abs(final_value - last) < eps_) break;
            last = final_value;

        }

        return int(final_value);
    }
    float sqrt_inv (float x){
        if (x <= 0.0f) return 0.0f;

        float xhalf = 0.5f*x;
        int i = *(int*)&x; // get bits for floating VALUE
        i = 0x5f375a86- (i>>1); // gives initial guess y0
        x = *(float*)&i; // convert bits BACK to float
        x = x*(1.5f-xhalf*x*x); // Newton step, repeating increases accuracy
        x = x*(1.5f-xhalf*x*x); // Newton step, repeating increases accuracy
        x = x*(1.5f-xhalf*x*x); // Newton step, repeating increases accuracy
        return int(1/x);
    }
public:
    Solution(): eps_(0.00001f) {}
private:
    float eps_;
};
int main(int argc, char* argv[])
{
    int n = 3;
    Solution s;
    std::cout<< s.sqrt_binary_section(3)<<std::endl;
    std::cout<< s.sqrt_newton(3)<<std::endl;
    std::cout<< s.sqrt_inv(3)<<std::endl;
    return 0;
}
