class FreqStack {
unordered_map<int,int> cnt;
int index;
priority_queue<vector<int>> heap;

public:
    FreqStack() {
        index=0;
    }
    
    void push(int val) {
        cnt[val]++;
        heap.push({cnt[val],index++,val});
    }
    
    int pop() {
        if(heap.empty())return -1;
        vector<int> q=heap.top();
        heap.pop();
        cnt[q[2]]--;
        return q[2];

    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */