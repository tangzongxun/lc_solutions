class Solution {
public:
    
    
    void skip_space(const string &s, size_t &pos) {
        if (pos >= s.size()) {
            return;
        }
        while (s[pos] == ' ' && pos < s.size()) {
            pos++;
        }
    }
    
    int read_flag(const string &s, size_t &pos) {
        if (pos >= s.size()) {
            throw runtime_error{"invalid"};
        }
        if (s[pos] == '-') {
            pos++;
            return -1;
        } 
        if (s[pos] == '+') {
            pos++;
            return 1;
        }
        return 1;
    }
    
    int64_t read_num(int flag, const string &s, size_t pos) {
        const int64_t positive_uplimit = ((int64_t)1 << 31) - 1;
        const int64_t negative_uplimit = (int64_t)1 << 31;
        
        int64_t ret = 0;
        while (pos < s.size()) {
            unsigned char c = s[pos];
            if (c < '0' || c > '9') {
                return ret;
            }
            int digit = c - '0';
            ret = ret * 10 + digit;
            if (flag > 0 && ret > positive_uplimit) {
                return positive_uplimit;
            }
            if (flag < 0 && ret > negative_uplimit) {
                return negative_uplimit;
            }
            pos++;
        }
        return ret;
    }
    
    int myAtoi(string s) {
        try {
            size_t pos = 0;
            skip_space(s, pos);
            int flag = read_flag(s, pos);
            int64_t num = read_num(flag, s, pos);
            return flag * num;    
        } catch (...) {
            return 0;
        }
        
    }
};
