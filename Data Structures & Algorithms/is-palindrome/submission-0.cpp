class Solution {
public:
    bool isPalindrome(string s) {
        for (char &c : s)
            c = tolower(c);

        s.erase(remove_if(s.begin(), s.end(),
                          [](char c) { return !isalnum(c); }),
                s.end());

        int n = s.size();

        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1])
                return false;
        }

        return true;
    }
};