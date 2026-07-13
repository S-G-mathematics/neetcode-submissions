class MyQueue {
private:
stack<int> a;
stack<int> b;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        int t=a.size()-1;
        while(t--){
            b.push(a.top());
            a.pop();
        }
        int ans=a.top();
        a.pop();
        while(!b.empty()){
            a.push(b.top());
            b.pop();
        }
        return ans;
    }
    
    int peek() {
        int t=a.size()-1;
        while(t--){
            b.push(a.top());
            a.pop();
        }
        int ans=a.top();
        while(!b.empty()){
            a.push(b.top());
            b.pop();
        }
        return ans;  
    }
    
    bool empty() {
        return a.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */