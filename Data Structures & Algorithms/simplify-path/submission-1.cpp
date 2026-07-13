class Solution {
public:
    string simplifyPath(string path) {
        int n=path.size();
        vector<string> pth;
        string temp="";
        for(char c:path){
            if(c=='/'){
                if(temp!="")pth.push_back(temp);
                temp="";
                continue;
            }else{
                temp=temp+c;
            }
        }
        if(temp!="")pth.push_back(temp);
        stack<string> st;
        int k=pth.size();
        for(int i=0;i<k;i++){
            if(pth[i]==".") continue;
            else if(pth[i]==".."){
                if(!st.empty())st.pop();
            }else{
                st.push(pth[i]);
            }
        }
        pth.clear();
        while(!st.empty()){
            pth.push_back(st.top());
            st.pop();
        }
        k=pth.size();
        if(k==0) return"/";
        string ans="/";
        for(int i=k-1;i>=0;i--){
            ans=ans+pth[i];
            ans=ans+"/";
        }
        if(ans!="/")ans.pop_back();
        return ans;
    }
};