class Solution {
public:
    void swap(int &a, int &b) {
        a=a^b;
        b=a^b;
        a=b^a;
        return {a, b};
    }
};