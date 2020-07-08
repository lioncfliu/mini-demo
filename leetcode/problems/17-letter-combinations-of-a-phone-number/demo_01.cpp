class Solution {
public:
    vector<string> letterCombinations(string digits) {
        std::vector<std::string> result = {};
        if (digits == "") return result;

        std::unordered_map<char, std::string> keys = {
            {'0', ""},
            {'1', ""},
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };
        std::string str = "";
        find(digits, 0, str, keys, result);

        return result;

    }
    void find(const std::string &digits, int pos, std::string str, std::unordered_map<char, std::string> &keys, std::vector<std::string> &result) {

        if (digits.size() == pos) {
            result.push_back(str);
            str = "";
            return;
        }
        for (char c : keys[digits[pos]]) {
            str += c;
            find(digits, pos + 1, str, keys, result);
            str.pop_back();
        }
        return;
    }
};
