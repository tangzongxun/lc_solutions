class Solution {
public:
    
    int next_num(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        set<int> memo;
        while (n != 1) {
            if (memo.find(n) != memo.end()) {
                return false;
            }
            memo.insert(n);
            n = next_num(n);
        }
        return true;
    }
};
