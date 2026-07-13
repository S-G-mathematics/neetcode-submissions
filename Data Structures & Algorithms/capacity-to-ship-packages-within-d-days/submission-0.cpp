class Solution {
public:
    int days(vector<int>& weights,int cap){
        int n=weights.size();
        int ans=1;
        int temp=0;
        for(int i=0;i<n;i++){
            if(temp+weights[i]<=cap)temp=temp+weights[i];
            else{
                temp=weights[i];
                ans++;
            }
        }
        return ans;
    }
    int shipWithinDays(vector<int>& weights, int d) {
        int l=*max_element(weights.begin(),weights.end());
        int n=weights.size();
        int r=accumulate(weights.begin(),weights.end(),0);
        int ans;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(days(weights,mid)>d){
                l=mid+1;
            }else if(days(weights,mid)<=d){
                ans=mid;
                r=mid-1;
            }
        }
        return ans;
    }
};