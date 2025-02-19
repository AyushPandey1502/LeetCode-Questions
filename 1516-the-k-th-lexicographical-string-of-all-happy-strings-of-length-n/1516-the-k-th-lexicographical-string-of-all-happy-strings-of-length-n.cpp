class Solution {
public:
    string getHappyString(int n, int k) {
        stack<string> st;
        st.push("");
        int index = 0;

        while(!st.empty()){
            string s = st.top();
            st.pop();
            if(s.size() == n){
                index++;
                if(index == k) return s;
                continue;
            }
            for(char ch = 'c'; ch >= 'a'; ch--){
                if(!s.empty() && s.back() == ch) continue;
                st.push(s+ch);
            }            
        }
        return "";
    }
};