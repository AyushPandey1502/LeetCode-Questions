class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int result = 0;

        for (char ch : s) {
            if (ch == 'b') {
                st.push(ch);
            } else { 
                if (!st.empty() && st.top() == 'b') {
                    result++;
                    st.pop();
                } else {
                    st.push(ch);
                }
            }
        }
        return result;
    }
};
