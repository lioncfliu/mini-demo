class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> result = {};
        
        if (nums.size() < 3) return result;

        /// sort in ascending order
        sort(nums.begin(), nums.end(), std::less<int>());
        int len = nums.size();
        int right = 0;
        int left = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) return result;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            /// double ptr 
            left =  i + 1;
            right = len - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (0 == sum) {
                    std::vector<int> v = {nums[i], nums[left], nums[right]};
                    result.push_back(v);
                    /// avoid duplicated 
                    while (left < right && nums[left] == nums[left +1]) {
                        ++left;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        --right;
                    }
                    /// find next
                    ++left;
                    --right;
                } else if (sum < 0) {
                    ++left;
                } else if (sum > 0) {
                    --right;
                }
            }
        }
        
        return result;
    }
};
