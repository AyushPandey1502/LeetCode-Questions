class Solution {
public:
    char solvingExp(char op, vector<char>& values){
        if(op == '!'){
            return values[0] == 't' ? 'f' : 't';
        }
        else if(op == '&'){
           for(int i = 0; i < values.size(); i++){
                if(values[i] == 'f') return 'f';
           } 
           return 't';
        }
        else{
            for(int i = 0; i < values.size(); i++){
                if(values[i] == 't') return 't';
            }
            return 'f';
        }
    }

    bool parseBoolExpr(string expression) {
        int n = expression.size();
        stack<char> st;
        for(int i = 0; i < n; i++){
            if(expression[i] == ',') continue;
            if(expression[i] == ')'){
                vector<char> values;
                while(st.top() != '('){
                    values.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op = st.top();
                st.push(solvingExp(op, values)); 
            }else{
                st.push(expression[i]);
            }
        }
        return (st.top() == 't' ? true : false);
    }
};