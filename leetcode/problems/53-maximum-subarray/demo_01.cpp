#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) { return 0; }

        int sum = 0;
        int final_sum = nums[0]; // first element of nums
        for (int i = 0; i < nums.size(); i++) {
            if (sum > 0) sum += nums[i];

            if (sum <= 0) sum = nums[i];
            if (final_sum < sum) final_sum = sum;
        }
        
        return final_sum;
    }
};

void TEST_case_01_ok() 
{
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums(arr, arr + sizeof(arr)/sizeof(arr[0]));
    Solution s;
    std::cout<<"maximum subarray:" << s.maxSubArray(nums) <<std::endl;
}
void TEST_case_02_ok() 
{
    int arr[] = {-2};
    vector<int> nums(arr, arr + sizeof(arr)/sizeof(arr[0]));
    Solution s;
    std::cout<<"maximum subarray:" << s.maxSubArray(nums) <<std::endl;
}

int main(int argc, char* argv[]) 
{
    TEST_case_01_ok();
    TEST_case_02_ok();
    return 0;
}
