class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,pair<int,int>> mpp;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(mpp.count(s[i])==0){
                mpp[s[i]].first=i;
            }
            mpp[s[i]].second=i;
        }
        vector<pair<int,int>> df;
        for(auto& it:mpp){
            df.push_back(it.second);
        }

        sort(df.begin(),df.end());
        for(auto it:df){
            cout<<it.first<<" "<<it.second<<endl;
        }
        n=df.size();
        vector<int> ans;
        int st=0;
        int end=df[0].second;
        for(int i=1;i<n;i++){
            if(df[i].first<=end){
                end=max(end,df[i].second);
            }else{
                ans.push_back(end-st+1);
                st=df[i].first;
                end=df[i].second;
            }
        }
        ans.push_back(end-st+1);
        return ans;
    }
};
