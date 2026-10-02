class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        unordered_map<int, int> mp;

        int left = 0;
        int maxLen = 0;

        for(int right = 0; right < fruits.size(); right++) {

            // add current fruit
            mp[fruits[right]]++;

            // if more than 2 fruit types
            while(mp.size() > 2) {

                mp[fruits[left]]--;

                // remove if frequency becomes 0
                if(mp[fruits[left]] == 0)
                    mp.erase(fruits[left]);

                left++;
            }

            // valid window
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};