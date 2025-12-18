#include <iostream>
using namespace std;
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        // INT的範圍在 - 2的31次方 到2的31次方減一  此case會overflow 要這樣處理
        if (dividend == INT_MIN && divisor == -1)
        {
            return INT_MAX;
        }
        // 處理sign
        int sign = dividend < 0 ^ divisor < 0 ? -1 : 1;
        long result = 0;
        long m = labs(dividend);
        long n = labs(divisor);
        // m>=n 要處理， 也有相等的情況
        while (m >= n)
        {
            long temp_divisor = n;
            int quotient = 1;
            // 除數乘倍去處理
            while (m >= (temp_divisor << 1))
            {
                temp_divisor <<= 1;
                quotient <<= 1;
            }
            m -= temp_divisor;
            result += quotient;
        }
        return sign < 0 ? -result : result;
    }
};