ass Solution {
public:
    string minWindow(string s, string t) {

        if (s.size() < t.size()) return "";

        unordered_map<char, int> t_char_counters;
        unordered_map<char, int> found_window;

        for (auto &c : t) {
            t_char_counters[c]++;
        }

        int left = 0;
        int right = 0;
        int begin = 0;
        int min_window_size = s.size() + 2;
        int t_len = t_char_counters.size();
        int found_counter = 0;
        while (right < s.size()) {
            // try to expend right of window
            char r_c = s[right];
            ++right;
            if (t_char_counters.count(r_c) > 0) {
                ++found_window[r_c];
                if (found_window[r_c] == t_char_counters[r_c]) {
                    ++found_counter;
                }
            }
            //cout<<"r_c:"<< r_c <<", found_couter: " << found_counter << std::endl;

            // try to shrink left of window
            while (found_counter == t_len) {
                if (right - left < min_window_size) {
                    min_window_size = right - left;
                    begin = left;
                }
                char  l_c = s[left];
                ++left;
                if (t_char_counters.count(l_c) > 0) {
                    //cout<<"found_window@"<<l_c << ":"<< found_window[l_c] <<std::endl;
                    if (found_window[l_c] == t_char_counters[l_c]) {
                        --found_counter;
                    }
                    --found_window[l_c];
                }

            }
        }
        if (min_window_size > s.size() ) return "";
        return s.substr(begin, min_window_size);
    }
};
