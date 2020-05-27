class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int step_1 = 0;
        int step_2 = 0;
        int pos = 0;
        while (1) {
            step_1 = nums[step_1];
            step_2 = nums[nums[step_2]];

            if (step_1 == step_2) break;
        }
        while (1) {
            pos = nums[pos];
            step_1 = nums[step_1];
            if (pos == step_1) break;
        }

        return pos;
        
    }
};

int main(int argc, char* argv[]) 
{
    return 0;
}
