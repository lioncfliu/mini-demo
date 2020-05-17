class MinStack {
public:
    /** initialize your data structure here. */
    MinStack(): head_(nullptr),invalid_value_(-99999) {
        
    }
    
    void push(int x) {
        StackNode *node = new StackNode;
        node->value = x;
        node->min_value = x;
        node->next = nullptr;

        if (! head_) {
            head_ = node;
        } else {
            int min = head_->min_value;
            if (x < min) {
                node->min_value = x;
            } else {
                node->min_value = min;
            }
            node->next = head_;
            head_ = node;
        }
    }
    
    void pop() {
        if (! head_)
            return ;

        StackNode *top = head_;
        head_ = head_->next;
        delete top;
    }
    
    int top() {
        if (! head_)
            return invalid_value_;

        return head_->value;
    }
    
    int getMin() {
        if (! head_)
            return invalid_value_;
                    
        return head_->min_value;

    }
private:
    struct StackNode {
        int value;
        int min_value;
        StackNode *next;
    };
private:
    StackNode *head_;
    int invalid_value_;
};

int main(int argc, char* argv[]) 
{
    return 0;
}
