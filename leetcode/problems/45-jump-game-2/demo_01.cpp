class Solution {
public:
    int jump(vector<int>& nums) {

        /// jump the bigest steps by every step
        int steps = 0;
        int max_pos = 0;
        int next = 0; // pos which next step jump to
        for (int i = 0; i < nums.size() - 1; ++i) {
            max_pos = max(max_pos, nums[i] + i);
            if (i == next) {
                next = max_pos;
                ++steps;
            }
        }
        return steps;
    }
};
