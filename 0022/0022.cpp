void generateParenthesisImpl(int level, int n, vector<string> &result, string tmpString) {
    if (n > 0) {
        generateParenthesisImpl(level + 1, n - 1, result, tmpString + '(');
    }
    if (level > 0) {
        generateParenthesisImpl(level - 1, n, result, tmpString + ')');
    }
    if (level == 0 && n == 0) {
        result.push_back(tmpString);
    }
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesisImpl(0, n, result, "");
        return result;
    }
};
