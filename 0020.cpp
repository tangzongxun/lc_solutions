bool isPair(char c1, char c2){
    if(c1 == '{' && c2 == '}' ||
       c1 == '(' && c2 == ')' ||
       c1 == '[' && c2 == ']'){
        return true;
    }
    return false;
}

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto c: s){
            if (stk.empty()){
                stk.push(c);
            } else{
                if(isPair(stk.top(), c)){
                    stk.pop();
                } else {
                    stk.push(c);
                }   
            }
        }
             
        if (stk.empty()){
            return true;
        }
        return false;
    }
};
               
