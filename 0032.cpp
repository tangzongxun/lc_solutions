class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty()){
            return 0;
        }
        
        vector<int> longest(s.size(), 0);
        
        // Initialize
        longest[0] = 0;
        if(s[0] == '(' && s[1] == ')'){
            longest[1] = 2;
        } else{
            longest[1] = 0;
        }
        
        // DP
        for(int i = 2; i < s.size(); i++){
            if(s[i] == '('){
                longest[i] = 0;
            } else if(s[i] == ')'){
                if(s[i - 1] == '('){
                    longest[i] = longest[i-2] + 2;
                } else if (s[i-longest[i-1]-1] == '('){
                    longest[i] = longest[i-1] + 2 + longest[i-longest[i-1]-2];
                } else{
                    longest[i] = 0;
                }
            }
        }
        
        return *max_element(longest.begin(), longest.end());
    }
};
