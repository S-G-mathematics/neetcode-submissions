class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n=tokens.size();
        int ans;
        for(int i=0;i<n;i++){
            string q=tokens[i];
            if(q!="+" && q!="-" && q!="/" && q!="*"){
                st.push(stoi(q));
            }else{
                if(tokens[i]=="+"){
                    int a=st.top();
                    st.pop();
                    int b=st.top();
                    st.pop();
                    st.push(a+b);
                }
                if(tokens[i]=="-"){
                    int a=st.top();
                    st.pop();
                    int b=st.top();
                    st.pop();
                    st.push(b-a);
                }
                if(tokens[i]=="*"){
                    int a=st.top();
                    st.pop();
                    int b=st.top();
                    st.pop();
                    st.push(a*b);
                }
                if(tokens[i]=="/"){
                    int a=st.top();
                    st.pop();
                    int b=st.top();
                    st.pop();
                    st.push(b/a);
                }
            }
        }
    return st.top();
    }
};
