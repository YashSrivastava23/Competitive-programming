/**
 * MINSTACK From Leetcode (https://leetcode.com/problems/min-stack/)
*/


class MinStack {
public:
    vector<long long> v;
    long min;
    MinStack() {
        
    }
    
    void push(long val) {
        if(v.size()==0) {
            v.push_back(val);
            min = val;
        } else {
            if(val<min) {
                v.push_back(2*val-min);
                min = val;
            } else {
                v.push_back(val);
            }
        }
    }
    
    void pop() {
        if(v.size()==0) {
            return;
        } else {
            if(v.back()<min) {
                min = 2*min - v.back();
                v.pop_back();
            } else {
                v.pop_back();
            }
        }
    }
    
    int top() {
        if(v.size()==0) {
            return -1;
        } else {
            if(v.back() < min) {
                return min;
            } else {
                return v.back();
            }
        }
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */