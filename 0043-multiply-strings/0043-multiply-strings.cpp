class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int n = num1.length();
        int m = num2.length();
        string result(m + n, '0');

        for (int i = m - 1; i >= 0; i--) {
            int carry = 0;
            for (int j = n - 1; j >= 0; j--) {
                int num = (num1[j] - '0') * (num2[i] - '0') + (result[i + j + 1] - '0') + carry;
                carry = num / 10;
                result[i + j + 1] = (num % 10) + '0';
            }
            result[i] = carry + '0';
        }

        for (int i = 0; i < result.length() - 1; i++) {
            if (result[i] != '0') {
                return result.substr(i);
            }
        }

        return result.substr(result.length() - 1);
    }
};
