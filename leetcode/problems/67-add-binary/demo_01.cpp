class Solution {
public:
    string addBinary(string a, string b) {
        
        if (a.empty()) return b;
        if (b.empty()) return a;

        std::string result((a.size() > b.size() ? a.size() : b.size()) + 1, ' ');
        int i = result.size();        
        int r_i = result.size() - 1;
        int a_i = a.size() - 1;
        int b_i = b.size() - 1;
        int plus = 0;
        int sum = 0;
        while (r_i >= 1) {

            sum = (  ((a_i >= 0 ? a[a_i] : '0') - '0')
                   + ((b_i >= 0 ? b[b_i] : '0') - '0') 
                   + plus);
            result[r_i] = sum % 2 + '0';
            plus =  sum / 2;

            --r_i;
            --a_i;
            --b_i;
        }
        //std::cout<< "result, plus:" << result<<","<<plus<<std::endl;
        if (plus) {
            result[0] = '1';
            return result;
        } else {
            return result.substr(1, result.size() - 1);
        }
    }
};
