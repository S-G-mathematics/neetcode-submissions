class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        res="";
        for(string q:strs){
            res=res+q;
            res=res+".";
        }
        return res;

    }

    vector<string> decode(string s) {
        vector<string> pol;
        string temp="";
        for(char t:s){
            if(t=='.'){
                pol.push_back(temp);
                temp="";
                continue;
            }
            temp=temp+t;
        }
        return pol;
    }
};
