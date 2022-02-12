class MinStack {
public:
    stack<int> x_stk;
    stack<int> min_stk;

    MinStack() {
        min_stk.push(INT_MAX);
    }
    
    void push(int val) {
        x_stk.push(val);
        min_stk.push(min(min_stk.top(), val));
    }
    
    void pop() {
        x_stk.pop();
        min_stk.pop();
    }
    
    int top() {
        return x_stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
};



class MinStack {
public:
    stack<long long> stk;
    int min_value;

    MinStack() {
        min_value = 0;
    }
    
    void push(int val) {
        if(!stk.empty()){
            long long diff = (long long)val - (long long)min_value;
            stk.push(diff);
            if (diff < 0)
                min_value = min_value + diff;   
        }
        else{
            stk.push(0);
            min_value = val;
        }
    }
    
    void pop() {
        if (!stk.empty())
        {
            long long diff = stk.top();
            if(diff < 0)
                min_value = min_value - diff;
            stk.pop();
        }
    }
    
    int top() {
        long long diff = stk.top();
        if (diff >= 0)
            return min_value + diff;
        else
            return min_value;
    }
    
    int getMin() {
        return min_value;
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