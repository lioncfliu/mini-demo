class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        return s2(heights);
    }

    int s2(vector<int> &heights) {
        // 参考学习单调递增栈
        int max_area = 0;
        // elem: index of elements in heights
        vector<int> stack;
        // 头尾insert 0 辅助计算
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i) {
            while (! stack.empty() && heights[stack.back()] > heights[i]) {
                int h = heights[stack.back()];
                stack.pop_back();
                int left = stack.back() + 1;
                int right = i - 1;
                int w = (right - left + 1);
                max_area = max(max_area, w * h);
            }
            stack.push_back(i);
        }
        return max_area;
    }
    /// pass, timeout
    int s1(vector<int> &heights) {
        int max_area = 0;
        for (int i = 0; i < heights.size(); ++i) {
            int j = i;
            int h = heights[i];
            int w = 1;
            /// left
            while (--j >=0 && heights[j]>=h) {
                ++w;
            }
            /// right
            j = i;
            while (++j < heights.size() && heights[j] >=h) {
                ++w;
            }

            max_area = max(max_area, h * w);
        }
        return max_area;
    }
};

int main(int argc, char *argv) 
{
    return 0;
}
