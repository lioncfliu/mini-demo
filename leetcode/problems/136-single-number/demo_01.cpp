#include <iostream>
#include <vector>
#include <map>
#include <assert.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return once_element_2(nums);
    }

    int once_element_1(vector<int>& nums) {
        map<int, int> elem_counter;
        for (int i = 0; i < nums.size(); ++i) {
            //map<int, int>::iterator iter = elem_counter.find(nums[i]);
            //if (iter != elem_counter.end()) elem_counter[nums[i]] ++;
            
            elem_counter[nums[i]] ++;
        }
        for (map<int, int>::iterator iter = elem_counter.begin(); 
            iter != elem_counter.end(); ++iter) {
            if (iter->second == 1) return iter->first;
        }
        return 0;
    }
    int once_element_2(vector<int>& nums) {
        /// lhs ^ rhs  
        /// 0 ^ x -> x
        /// x ^ x -> 0
        /// x1 ^ x2 ^ x3 ^ ... ^ x3 ^ x1 ^ x2 ^ once_element -> once_element

        int once_elem = 0;
        for (int i = 0; i < nums.size(); ++i) {
            once_elem = once_elem ^ nums[i];
        }
        return once_elem;
    }
};

int main(int argc, char* argv[]) 
{

    vector<int> nums{4, 1, 2, 1, 2, 5, 7, 7, 5};   
    Solution s;
    
    assert(4 == s.singleNumber(nums));
    return 0;
}
