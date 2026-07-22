class Solution {
public:
    vector<int> st;
    int esu;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        st=vector<int>(k,0);
        sort(nums.begin(),nums.end(),greater<int>());
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%k!=0)return false;
        esu=sum/k;
        return dfs(nums,0,k);
    }

    bool dfs(vector<int>& nums,int idx,int k){
        if(idx==nums.size()){
            for(int i=0;i<k;i++){
                if(st[i]!=esu) return false;
            }
            return true;
        }
        bool p=false;
        for(int i=0;i<k;i++){
            st[i]=st[i]+nums[idx];
            if(st[i]<=esu)p=p||dfs(nums,idx+1,k);
            st[i]=st[i]-nums[idx];
            if(st[i]==0) break;
        }
        return p;
    }
};