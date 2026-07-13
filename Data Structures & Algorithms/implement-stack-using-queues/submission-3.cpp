class MyStack {
private:
queue<int> a;
queue<int> b;
int size;
public:
    MyStack() {
        size=0;
    }
    
    void push(int x) {
        a.push(x);
        size++;
    }
    
    int pop() {
        int t=size-1;
        int s=size-1;
        while(t--){
            b.push(a.front());
            a.pop();
        }
        int ans=a.front();
        a.pop();
        while(s--){
            a.push(b.front());
            b.pop();
        }
        size--;
        return ans;
    }
    
    int top() {
        int t=size-1;
        while(t--){
            b.push(a.front());
            a.pop();
        }
        int ans=a.front();
        b.push(a.front());
        a.pop();
        while(!b.empty()){
            a.push(b.front());
            b.pop();
        }
        return ans;       
        
    }
    
    bool empty() {
        return a.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */