class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0) return 0;
        if(n==1)return 0;
        vector<int> suffix(n);
        vector<int> prefix(n);
        prefix[0]=0;
        for(int i=1;i<n;i++){
            prefix[i]=max(prefix[i-1],height[i-1]);
        }
        suffix[n-1]=0;
        for(int i=n-2;i>=0;i--){
            suffix[i]=max(suffix[i+1],height[i+1]);
        }
        int ar=0;
        for(int i=0;i<n;i++){
            ar=ar+max(0,(min(suffix[i],prefix[i])-height[i]));
        }
        return ar;
    }
};
