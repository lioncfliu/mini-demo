class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int begin = 0, end = 0;
        int local_max_len = 0;
        int final_max_len = 0;
        while (end < s.size()) {
            char curr = s[end];
            for (int i = begin; i < end; i++) {
                if (curr == s[i]) {
                    begin = i + 1;
                    break;
                }
            }
            end ++;
            local_max_len = end - begin;
            final_max_len = max(final_max_len, local_max_len);
        }
        return final_max_len;
    }
};

int main(int argc, char* argv[]) 
{
    return 0;
}
