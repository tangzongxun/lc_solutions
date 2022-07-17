class Solution {
public:
    
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }
        
        bool sign = !((dividend < 0) ^ (divisor < 0));
        long result = 0;
        
        long dividend_l = labs(dividend);
        long divisor_l = labs(divisor);
        
        long i = 1;
        long div_num = divisor_l;
        
        while (div_num < dividend_l){
            i = i << 1;
            div_num = div_num << 1;
        }
        
        while(dividend_l >= divisor_l){
            if (dividend_l >= div_num){
                dividend_l -= div_num;
                result += i;
            }
            i = i >> 1;
            div_num = div_num >> 1;
        }
        
        
        return sign ? result : -result;
    }
};
