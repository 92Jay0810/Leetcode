class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0){
            return 0;
        }
        if(n == 0){
            return 1;
        }
        double result = fastPow(x , static_cast<long>(n));
        return n > 0 ? result : 1/result;
    }
    double fastPow(double x, long n){
        if(n == 0){
            return 1;
        }
        double half = fastPow(x,n/2);
        //把n/2 次方奇數補回來
        //此方法只要logn
        return n % 2 == 0 ? half * half : x * half * half ;
    }
};
