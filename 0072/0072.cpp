class Solution {
public:
    int minDistance(string word1, string word2) {
        auto size1 = word1.size();
        auto size2 = word2.size();
        auto distance = vector<vector<int>>(size1, vector<int>(size2, -1));
        
        function<int(int, int)> solve;
        solve = [&](int i, int j){
            if (i < 0){
                if (j < 0){
                    return 0;
                } else{
                    return j+1;
                }
            }
            if (j < 0){
                return i+1;
            }
            if (distance[i][j] != -1){
                return distance[i][j];
            }
            if (word1[i] == word2[j]){
                int solution = solve(i-1, j-1);
                distance[i][j] = solution;
                return solution;
            } else{
                int insert_d = solve(i-1, j) + 1;
                int delete_d = solve(i, j-1) + 1;
                int replace_d = solve(i-1, j-1) + 1;
                int solution = min({insert_d, delete_d, replace_d});
                distance[i][j] = solution;
                return solution;
            }
        };
        return solve(size1-1, size2-1);
    }
};
