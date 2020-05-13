// created by lioncfliu on 2020/05/10.
//

#include <iostream>
#include <assert.h>
#include <vector>
#include <map>

/**
 * @brief  Try to find one or two numbers which sum of them equals `param n`.
 * */
bool tryFindSumOfTwoNumsEqualsN(int n, 
    int len, 
    int list[], 
    bool r[], 
    std::vector<int> &index_v) 
{
    //
    //todo: check input invalid or not
    //

    
    // s = a + b
    // 1. s = a + 0 , found
    // 2. s = a + b , found 
    // 3. s > max(list), found max(list) then try (local best answer)
    // 4. s < min(list), no element is available
    // 5. no element in list

    int max = 0, min = 0;
    int max_val_index = 0, min_val_index = 0;
    int s = n;
    
    std::map<int, int> index_map;
    bool found = false;
    
    for (int i = 0; i < len; ++i) {
        // holded by other, continue
        if (r[i]) continue;

        // record min & max of list
        if (list[i] > max && list[i] <= s) { 
            max = list[i]; 
            max_val_index = i;
        }

        if (list[i] < min) { 
            min = list[i];
            min_val_index = i;
        }
        
        // 1. s =  a + 0
        if (s == list[i]) {
            index_v.push_back(i);
            found = true;
            break;
        }
        
        // 2. s = a + b
        const auto &iter = index_map.find(s - list[i]);
        if (iter != index_map.end()) {
            if (iter->second < i) {
                index_v.push_back(iter->second);
                index_v.push_back(i);   
            } else {
                index_v.push_back(i);   
                index_v.push_back(iter->second);
            }
            found = true;
            break;
        } else {
            index_map.insert(std::pair<int, int>(list[i], i));
        } 
    }
    if (! found) {
        // 3. found max
        if (max > 0) {
            index_v.push_back(max_val_index); 
        }
        if (s < min) {
            // no available element;
        }
    }

    return found;
}

int FindMaxStore(const int len, int s[], const int c, bool r[])
{
    //
    // todo: check input valid or not
    //
    bool found = false;
    int rest = c;
    int max_try = len;
    std::vector<int> index_v;
    bool end = false; 
    bool final_found = false;
    
    while (! end && max_try) {
            --max_try;
            for ( int i = 0; i < len; ++i ) {

            if (rest == 0) { 
                break; 
                end = true;
            }

            final_found = final_found || r[i];
            if (r[i]) continue;
            //std::cout<<"rest:" <<rest <<std::endl;

            index_v.clear(); 
            found = tryFindSumOfTwoNumsEqualsN(rest, len, s, r, index_v);
            if (found) {
                for (auto &e : index_v) {
                    r[e] = true;
                    rest -= s[e];
                    final_found = final_found || r[e];
                }
                // end
                //std::cout<<"found a b" <<std::endl;
                end = true;
                break;
            } else {
                if (! index_v.empty()) {
                    // found max of list ,then try
                    for (auto &e : index_v) {
                        r[e] = true;
                        rest -= s[e];
                        final_found = final_found || r[e];
                    }
                } else {
                    // end
                    //std::cout<<"rest < min" <<std::endl;
                    end = true;
                    break;
                }
            }
        }
    }
    return (final_found ? 0 : -1);
}

void check_result(const int len, int s[], int c, bool r[]) 
{
    int sum = 0;
    int found_counter = 0;
    for (int i = 0; i < len; ++i) {
        std::cout<<s[i] <<"@[" <<i<< "]" << (r[i] ? "*":" ") << (i+1 < len ? ",": " ");
        if(r[i]) {
            sum += s[i]; 
            ++found_counter;
        }
    }
    std::cout<<std::endl<<"sum(found)/C :" <<sum <<"/" <<c<< ", cost rate:"
    << float(sum) / float(c) <<", found count:"<<found_counter <<std::endl;
}

void TEST_case_01_ok()
{
    int s[] = { 3, 7, 8, 8, 9, 10, 11, 15, 18, 19, 22, 30, 43, 100};   
    int len = sizeof(s) / sizeof(int);
    int c_list[] = {1, 2, 3, 12, 15, 44, 55, 66, 77, 88, 89, 99, 110, 131, 132, 150, 177, 
            200, 211, 222, 227, 228, 229,230, 233, 237, 238, 240, 241, 243, 244, 245, 255,
            256, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272,
            273, 274, 275, 276, 277, 280, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 
            300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 
            316, 317, 318, 319, 331, 333, 357, 431, 479, 500};

    for (auto &e : c_list) {
        bool r[len];
        for (auto &e : r) e = false;
    
        std::cout<< "// ---- Case " << e << " ---- //"<<std::endl;
        if (0 == FindMaxStore(len, s, e, r)) 
            std::cout<<"Find succeed !" <<std::endl;
        else
            std::cout<<"Find failed !" <<std::endl;
        check_result(len, s, e, r);
    }
}

void TEST_case_01_some_not_found()
{
    int s[] = { 19, 22, 30, 43, 100};   
    int len = sizeof(s) / sizeof(int);
    int c_list[] = {15, 17, 29, 31, 40, 45, 57, 77, 89, 99, 150, 200 };

    for (auto &e : c_list) {
        bool r[len];
        for (auto &e : r) e = false;
    
        std::cout<< "// ---- Case " << e << " ---- //"<<std::endl;
        if (0 == FindMaxStore(len, s, e, r))
            std::cout<<"Find succeed !" <<std::endl;
        else
            std::cout<<"Find failed !" <<std::endl;
        check_result(len, s, e, r);
    }
}
int main(int argc, char* argv[]) 
{
    TEST_case_01_ok();
    TEST_case_01_some_not_found();
    return 0;
}
