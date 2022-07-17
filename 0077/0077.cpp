class Solution {
public:
    vector<vector<int>> realCombine(int start, int end, int k){
        vector<vector<int>> solutions{};
        if (end - start < k || k <= 0){
            return solutions;
        }
        
        for(int i = start; i < end-k+1; i++){
            vector<int> comb{i};
            auto remains = realCombine(i+1, end, k-1);
            if (remains.empty()){
                solutions.push_back(comb);
            } else{
                for (auto& r: remains){
                    auto newComb = comb;
                    newComb.insert(newComb.end(), r.begin(), r.end());
                    solutions.push_back(newComb);
                }
            }

        }
        return solutions;
    }
    
    vector<vector<int>> combine(int n, int k) {
        return realCombine(1, n+1, k);
    }
};
