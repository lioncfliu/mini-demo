ass Solution {
public:
    int climbStairs(int n) {
        if (n == 1 || n == 2) return n;

        // n >=3
        // case 1: [n-1]--jump--1 step--to--[n]
        // case 2: [n-2]--jump--2 steps--to--[n]
        int n_i = 0;
        int n_1 = 1;
        int n_2 = 2;
        for (int i = 3; i <= n; ++i) {
            n_i = n_1 + n_2;
            n_1 = n_2;
            n_2 = n_i;
        }

        return n_2;
    }

};
