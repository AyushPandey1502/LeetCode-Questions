class Solution {
public:
    double Sqrt(int n) {
        if (n < 2)
            return double(n);

        double sqrt = n / 2;
        double temp = 0;

        while (sqrt != temp) {
            temp = sqrt;
            sqrt = (n / temp + temp) / 2;
        }

        return sqrt;
    }

    bool isPerfectSquare(int num) {
        double a = Sqrt(num);
        double b = ceil(Sqrt(num));
        if (a == b)
            return true;
        return false;
    }
};
