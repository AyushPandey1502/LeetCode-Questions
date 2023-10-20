class Solution
{ // There is Reason why this questioh has so low accuracy
public:
    int divide(int dividend, int divisor)
    {
        int sgn = ((dividend < 0) ^ (divisor < 0));
        long long int d = abs(dividend), dv = abs(divisor), ans = 0;
        if (dv == 1)
            ans = d;
        else
            while (d >= dv) 
            {
                ++ans;
                d -= dv;
            }
        if (sgn == 1)
            ans = -ans;
        return ((ans < INT_MIN) ? INT_MIN : ((ans > INT_MAX) ? INT_MAX : ans ));
    }
};