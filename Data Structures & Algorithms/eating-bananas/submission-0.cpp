class Solution {
public:
    int hours(vector<int>& piles,int k){
        int n=piles.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans=ans+ceil((double)piles[i]/k);
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        int ans;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(hours(piles,mid)>h){
                l=mid+1;
            }
            else{
                r=mid-1;
                ans=mid;
            }
        }
        return ans;
    }
};
