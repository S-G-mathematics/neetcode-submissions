class Solution {
public:
    int romanToInt(string s) {
        string a="IX";
        string b="IV";
        string c="XC";
        string d="XL";
        string e="CD";
        string f="CM";
        int ans=0;
        
        size_t pos = s.find(a);

        if (pos != string::npos) {
            s.erase(pos, a.size());
            ans += 9;
        }
         pos = s.find(b);

        if (pos != string::npos) {
            s.erase(pos, b.size());
            ans += 4;
        }
         pos = s.find(c);

        if (pos != string::npos) {
            s.erase(pos, c.size());
            ans += 90;
        }
         pos = s.find(d);

        if (pos != string::npos) {
            s.erase(pos, d.size());
            ans += 40;
        }
         pos = s.find(e);

        if (pos != string::npos) {
            s.erase(pos, e.size());
            ans += 400;
        }
         pos = s.find(f);

        if (pos != string::npos) {
            s.erase(pos, f.size());
            ans += 900;
        }

        for(char c:s){
            if(c=='I')ans=ans+1;
            if(c=='V')ans=ans+5;
            if(c=='X')ans=ans+10;
            if(c=='L')ans=ans+50;
            if(c=='C')ans=ans+100;
            if(c=='D')ans=ans+500;
            if(c=='M')ans=ans+1000;
        }
        return ans;
    }
};