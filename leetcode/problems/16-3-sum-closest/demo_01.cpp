class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        /// sort 
        std::sort(nums.begin(), nums.end(), std::less<int>());
        for (auto e: nums) {
            std::cout<<e <<",";
        }
        std::cout<<std::endl;
        long long int min_sum = INT_MAX;
        int left = 0;
        int right = 0;
        int sum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            left = i + 1;
            right = nums.size() - 1;

            while (left < right) {
                sum = nums[i] + nums[left] + nums[right];

                if (sum == target) return sum;

                if (std::abs(sum - target) < std::abs(min_sum - target)) {
                    min_sum = sum;    
                }
                if (sum < target) ++left;
                if (sum > target )--right;
            }
        }
        return min_sum;
    }
};
