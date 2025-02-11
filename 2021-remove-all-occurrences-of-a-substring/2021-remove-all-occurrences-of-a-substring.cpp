class Solution {
public:
    bool match(stack<char> st, string part, int m){
        stack<char> temp = st;
        for(int i = m-1; i >= 0; i--){
            if(temp.top() != part[i]) return false;
            temp.pop();
        }
        return true;
    }

    string removeOccurrences(string s, string part) {
        stack<char> st;
        int n = s.size(), m = part.size();

        for(int i = 0; i < n; i++){
            st.push(s[i]);
            if(st.size() >= m && match(st, part, m)){
                for(int j = 0; j < m; j++) st.pop();
            }
        }

        string result = "";
        while(!st.empty()){
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};