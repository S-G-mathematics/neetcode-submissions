class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<string> s;
        int n=operations.size();
        for(int i=n-1;i>=0;i--){
            s.push(operations[i]);
        }
        vector<int> record;
        while(!s.empty()){
            string q=s.top();
            s.pop();
            if (isdigit(q.back())) {
                record.push_back(stoi(q));
            }else if(q=="+"){
                record.push_back(*(record.end()-1) + *(record.end()-2));
            }else if(q=="C"){
                record.pop_back();
            }else{
                record.push_back(record.back()*2);
            }
        }
        return accumulate(record.begin(),record.end(),0);
    }
};