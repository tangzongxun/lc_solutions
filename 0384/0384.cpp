class Solution {
public:
    Solution(vector<int> nums) 
        :origin{nums}, shuffled{nums}
    {
        // generate random numbers
        random_device rd;
        this->gen = mt19937(rd());
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        size_t len = shuffled.size();
        for(int i = 0; i < len; i++){
            uniform_int_distribution<> dis(i, len-1);
            int rd_num = dis(gen);
            swap(shuffled[i], shuffled[rd_num]);
        }
        return shuffled;
    }

private:
    vector<int> origin;
    vector<int> shuffled;
    
    mt19937 gen;
};
