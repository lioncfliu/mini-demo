class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        if (nums.empty()) return 1;
        
        int begin = 0;
        int end = nums.size();

        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] > begin && nums[i] < end && nums[i] != nums[nums[i]]) {
                std::swap(nums[i], nums[nums[i]]);
            }
        }

        for (int i = 1; i < end; ++i) {
            if (i != nums[i]) return i;
        }

        return (nums[0] == end) ? end + 1 : end;
    }
};
