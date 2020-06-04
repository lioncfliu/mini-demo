#include <iostream>
#include <stack>
#include <string>

using namespace std;


class Solution {
public:
    string decodeString(string s) {
        stack<string> expr_stack;
        stack<int> num_stack;
        string expr_str = "";
        string result = "";
        
        int num = 0;

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            cout<<"i-"<<i <<":" <<  c << endl;
            if (c >= '0' && c <= '9') {
            
                cout<< "c->num: " << c << ", digit:" << (c- '0') << endl;
                num = num * 10 + (c - '0');
                cout<< "num: " << num << endl;
                if (i+1 < s.size()) {
                    c = s[i+1];
                    if ((c < '0' || c > '9')) {
                        num_stack.push(num);
                        cout<< "found num: " << num << endl;
                        num = 0;
                    }
                }
            } else {

                if ('[' == c) {
                    string str(1, c);
                    expr_stack.push(str);
                } else if (']' == c ) {
                    
                    string expr = "";
                    while ("[" != expr_stack.top()) {
                        
                        expr.insert(0, expr_stack.top());
                        expr_stack.pop();
                    }

                    // pop "["
                    expr_stack.pop();
                
                    int dup = 0;
                    string dup_str = "";
                    cout<< "expr_str:" << expr <<", num: "<< num_stack.top() << endl;
                    if (! num_stack.empty()) { 
                        dup = num_stack.top();
                        while (dup--) dup_str += expr;
                        cout<< "dup_str:" << dup_str <<", result:"<< result << endl;
                    }

                    num_stack.pop();
                    if (num_stack.empty()) {
                        result += dup_str;
                        cout<<"num_stack is empty, result:"<< result << endl;
                        
                    } else {
                        expr_stack.push(dup_str); 
                        cout<<"expr_stack top:" << expr_stack.top()<< endl;
                    }  

                } else {
                    string str(1, c);

                    cout <<"found str:"<< str << ", expr_str:" << expr_str<< endl;
                    expr_str += str;
                    if (i+1 < s.size()) {
                        c = s[i+1];
                        if ((c >= '0' && c <= '9') || ']' == c) {
                            if ( num_stack.empty()) {
                                result += expr_str;
                                expr_str  = "";

                            } else {
                                expr_stack.push(expr_str);
                                expr_str = "";
                            }
                        }
                    } else if (i == s.size() -1) {
                        result += expr_str;
                    }

                }
            }
        }
        return result;
    }
};


int main(int argc, char* argv[]) 
{
    Solution s;
    string input = "3[a]2[bc]";
    input = "2[abc]3[cd]ef";
    input = "xx3[a2[c]]yy1[zz]ooo";
    string output = s.decodeString(input);
    cout<< "input: " << input << endl;
    cout<< "output: " << output << endl;
    
}
