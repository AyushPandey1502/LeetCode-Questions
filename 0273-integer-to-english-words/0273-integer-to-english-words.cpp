
class Solution {
public:
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";

        unordered_map<int, string> map = {
            {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"},
            {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"},
            {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"},
            {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"},
            {19, "Nineteen"}, {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"},
            {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"},
            {90, "Ninety"}, {100, "Hundred"}, {1000, "Thousand"}, {1000000, "Million"},
            {1000000000, "Billion"}
        };

        string result = intToString(num, map);
        result.pop_back();
        return result;
    }

private:
    string intToString(int num, unordered_map<int, string>& map) {
        if (num == 0)
            return "";
        else if (num < 20)
            return map[num] + " ";
        else if (num < 100)
            return map[num - num % 10] + " " + intToString(num % 10, map);
        else if (num < 1000)
            return map[num / 100] + " Hundred " + intToString(num % 100, map);
        else if (num < 1000000)
            return intToString(num / 1000, map) + "Thousand " +
                   intToString(num % 1000, map);
        else if (num < 1000000000)
            return intToString(num / 1000000, map) + "Million " +
                   intToString(num % 1000000, map);
        else
            return intToString(num / 1000000000, map) + "Billion " +
                   intToString(num % 1000000000, map);
    }
};