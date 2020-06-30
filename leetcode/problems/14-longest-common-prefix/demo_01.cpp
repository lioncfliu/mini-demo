class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    
        if (strs.empty()) return "";
        
        // sort strs first by ascii
        std::sort(strs.begin(), strs.end(), std::less<std::string>());
        std::string min_str = strs[0];
        std::string max_str = strs[strs.size() - 1];

        std::cout<<"min_str:" << min_str << std::endl;
        std::cout<<"max_str:" << max_str << std::endl;

        int i = 0;
        for (i = 0; i < min_str.size(); ++i) {
            if (min_str[i] != max_str[i]) {
                break;
            }
        }

        return min_str.substr(0, i);
    }
};
