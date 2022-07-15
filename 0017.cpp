static map<char, vector<char>> table{
    {'2', {'a', 'b', 'c'}},
    {'3', {'d', 'e', 'f'}},
    {'4', {'g', 'h', 'i'}},
    {'5', {'j', 'k', 'l'}},
    {'6', {'m', 'n', 'o'}},
    {'7', {'p', 'q', 'r', 's'}},
    {'8', {'t', 'u', 'v'}},
    {'9', {'w', 'x', 'y', 'z'}}
};

class Solution {
public:
    vector<string> append(const vector<string> result, char digit) {
        vector<string> output;
        if (digit < '2' || digit > '9') {
            throw runtime_error("invalid input");
        }
        for (auto c : table[digit]) {
            for (auto &s : result) {
                output.push_back(s + c);
            }
        }
        return output;
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return vector<string>{};
        }
        vector<string> result{""};
        for (auto digit : digits) {
            result = append(result, digit);
        }
        return result;
    }
};
