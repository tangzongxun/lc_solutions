const int MAX = ((1<<31) - 1);

class Solution {
public:
    int reverse(int x) {
        bool positive = x >= 0 ? true : false;
        x = abs(x);
        
        vector<int> digits;
        while(x != 0){
            digits.push_back(x % 10);
            x = x / 10;
        }
        
        int ret = 0;
        for(int i: digits){
            if (ret > (MAX-i)/10) {
                return 0;
            }
            ret = ret * 10 + i;
        }
        
        return positive ? ret : -ret;
    }
};
