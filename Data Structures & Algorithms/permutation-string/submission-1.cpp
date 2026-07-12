class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int a=s1.size();
        int b=s2.size();
        string temp=s2.substr(0,a);
        sort(s1.begin(),s1.end());
        for(int i=a;i<b;i++){
            string sert=temp;
            sort(sert.begin(),sert.end());
            if(sert==s1)return true;
            temp.erase(0,1);
            temp=temp+s2[i];
        }
        string sert=temp;
        sort(sert.begin(),sert.end());
        if(sert==s1)return true;
        return false;
    }
};
