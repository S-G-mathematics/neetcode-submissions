class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> um;
        if(s.size()!=t.size()) return false;
        for (auto v:s){
            um[v]++;
        }
        for (auto v:t){
            if(--um[v]<0){
                return false;
            }
        }
        return true;

    }
};
