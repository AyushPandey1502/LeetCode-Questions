bool checkPair(char op1, char op2) {
    return ((op1 == '(' && op2 == ')') || (op1 == '{' && op2 == '}') || (op1 == '[' && op2 == ']'));
}

bool isValid(char* s) {
    int len = strlen(s);
    char* stack = (char*)malloc(len * sizeof(char));
    int top = -1;

    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (top == -1 || !checkPair(stack[top], s[i])) {
                free(stack);
                return false;
            }
            top--; 
        }
    }

    free(stack); 

    return top == -1;
}