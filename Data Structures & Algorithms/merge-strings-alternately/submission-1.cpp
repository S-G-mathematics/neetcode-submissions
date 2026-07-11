class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int w1=word1.size();
        int w2=word2.size();
        int a=0;int b=0;
        string s="";
        while(a<w1 || b<w2){
            if(a<w1) s=s+word1[a++];
            if(b<w2) s=s+word2[b++];   
        }
        return s;
    }
};