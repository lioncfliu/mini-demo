class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int curr_max = 1, curr_min = 1;
        int final_max = INT_MIN;
        int tmp = 0;
        for (int i = 0; i < nums.size(); ++i) {
            /// swap(max, min) while value less than 0
            if (nums[i] < 0) {
                tmp = curr_max;
                curr_max = curr_min;
                curr_min = tmp;
            }

            curr_max = std::max<int>(curr_max * nums[i], nums[i]);
            curr_min = std::min<int>(curr_min * nums[i], nums[i]);

            final_max = max(curr_max, final_max);
        }
        return final_max;
    }
};

int main() 
{

    return 0;
}
