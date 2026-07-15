class Solution {
public:
    string decodeString(string s) {
        stack<string> st;

        for (char c : s) {
            if (c != ']') {
                st.push(string(1, c));
            } else {
                // Get encoded string
                string temp = "";
                while (st.top() != "[") {
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop(); // remove '['

                // Get number
                string k = "";
                while (!st.empty() && isdigit(st.top()[0])) {
                    k = st.top() + k;
                    st.pop();
                }

                int cnt = stoi(k);

                // Repeat string
                string rep = "";
                while (cnt--) {
                    rep += temp;
                }

                st.push(rep);
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};