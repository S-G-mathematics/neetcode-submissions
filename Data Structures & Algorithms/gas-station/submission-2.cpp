class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        if(accumulate(gas.begin(),gas.end(),0)<accumulate(cost.begin(),cost.end(),0)) return -1;
        int fuel=0;
        int st=0;
        for(int i=0;i<n;i++){
            fuel=fuel+gas[i]-cost[i];
            if(fuel<0){
                st=(i+1);
                fuel=0;
            }
        }
        return st;
    }
};
