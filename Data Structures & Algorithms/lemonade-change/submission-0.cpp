class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> freq;
        for(int i=0;i<bills.size();i++){
            freq[bills[i]]++;
            if(bills[i]==5)continue;
            else if(bills[i]==10){
                if(freq[5]==0)return false;
                freq[5]--;
            }else{
                if((freq[5]>=3)){
                    freq[5]=freq[5]-3;
                    continue;
                }else if(freq[5]>=1 && freq[10]>=1){
                    freq[5]=freq[5]-1;
                    freq[10]=freq[10]-1;
                    continue;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};