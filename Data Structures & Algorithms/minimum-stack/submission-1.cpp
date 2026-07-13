class MinStack {
private:
stack<int> stk;
stack<int> mstk;

public:
    MinStack() {
    }
    
    void push(int val) {
        if(stk.empty()){
            stk.push(val);
            mstk.push(val);
        }else{
            int q=mstk.top();
            stk.push(val);
            mstk.push(min(val,q));
        }
    }
    
    void pop() {
        if(stk.empty())return;
        stk.pop();
        mstk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return mstk.top();
    }
};
