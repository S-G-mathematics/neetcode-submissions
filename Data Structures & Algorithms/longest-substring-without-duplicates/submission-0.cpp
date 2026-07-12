class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int n=s.size();
        string q="";
        unordered_map<char,int> freq;
        for(int i=0;i<n;i++){
            q=q+s[i];
            freq[s[i]]++;
            while(freq[s[i]]>1){
                freq[q[0]]--;
                q.erase(0,1);
            } 
            ans=max(ans, (int)q.size());
        }
    return ans;
    }

};