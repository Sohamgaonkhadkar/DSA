class Solution {
public:
    bool isBitSet(int n, int i) {
        
        // Check ith bit
        if (n & (1 << i))
            return true;
        
        return false;
    }
};