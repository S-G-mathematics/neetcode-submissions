class KthLargest {
private:
priority_queue<int> pq;
int ko;
public:
    KthLargest(int k, vector<int>& nums) {
        ko=k;
        for(int n:nums){
            pq.push(n);
        }
    }
    
    int add(int val) {
        int t=ko-1;
        pq.push(val);
        vector<int> temp;
        while(t--){
            temp.push_back(pq.top());
            pq.pop();
        }
        int aa=pq.top();
        for(int a:temp){
            pq.push(a);
        }
        return aa;
    }
};
