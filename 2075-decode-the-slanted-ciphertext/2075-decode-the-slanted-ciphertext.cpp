class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        if (rows == 1) return encodedText;

        int cols = n / rows;
        string result;
        result.reserve(n);

        for (int col = 0; col < cols; col++) {
            int r = 0, c = col;
            while (r < rows && c < cols) {
                result += encodedText[r * cols + c];
                r++;
                c++;
            }
        }
        while (!result.empty() && result.back() == ' ') result.pop_back();
        return result;
    }
};