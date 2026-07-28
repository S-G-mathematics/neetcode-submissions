class Solution {
public:
    bool canyou(int idx,vector<int>& gas,vector<int> &cost){
        if(gas[idx]<cost[idx])return false;
        int fuel=0;
        int n=gas.size();
        int i=idx;
        do{
            fuel=fuel+gas[idx];
            if(fuel<cost[idx])return false;
            fuel=fuel-cost[idx];
            idx=(idx+1)%n;
        }while(i!=idx);
        return true;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i=0;i<gas.size();i++){
            if(canyou(i,gas,cost))return i;
        }
        return -1;
    }
};
