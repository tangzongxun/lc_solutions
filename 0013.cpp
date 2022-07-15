class Solution {
public:
    int romanToInt(string s) {
        static std::map<char, int> table{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        if (s.empty()) {
            return 0;
        }
        int result = 0;
        for (size_t i = 0; i < s.size() - 1; i++) {
            if (table[s[i]] < table[s[i+1]]) {
                result -= table[s[i]];
            } else {
                result += table[s[i]];
            }
        }
        result += table[s[s.size() - 1]];
        return result;
    }
};
