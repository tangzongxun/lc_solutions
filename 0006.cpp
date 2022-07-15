class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1){
            return s;
        }
        
        vector<string> rows(numRows);
        
        int row = 0;
        bool ascend = true;
        for(char c : s){
            rows[row] += c;
            
            if(ascend){
                row++;
            } else{
                row--;
            }
            
            if(row == 0){
                ascend = true;
            }
            if(row == numRows - 1){
                ascend = false;
            }
        }
        
        string ret;
        for(auto& s : rows){
            ret += s;
        }
        return ret;
    }
};
