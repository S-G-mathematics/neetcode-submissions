class Solution {
public:
    bool canJump(vector<int>& arr) {
        int m=0;
        for(int i=0;i<arr.size();i++){
            if(i>m) return false;
            if(m<arr[i]+i){
                m=arr[i]+i;
            }
        }
            if(m>=arr.size()-1){
                return true;
            }else{
                return false;
            }
    }
};
