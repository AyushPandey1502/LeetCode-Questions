int reverse(int x) {
    int reversed = 0;
    
    while (x != 0) {
        int lastDigit = x % 10;
        
        if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && lastDigit > 7)) {
            return 0;
        }
        if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && lastDigit < -8)) {
            return 0;
        }
        
        reversed = reversed * 10 + lastDigit;
        x /= 10;
    }
    
    return reversed;
}