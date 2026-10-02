class Solution {
public:

    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();

        // Total cards must divide evenly
        if(n % groupSize != 0) {
            return false;
        }

        unordered_map<int,int> freq;

        // Count frequencies
        for(int num : hand) {
            freq[num]++;
        }

        // Min Heap
        priority_queue<
            int,
            vector<int>,
            greater<int>
        > pq;

        // Insert unique numbers
        for(auto it : freq) {
            pq.push(it.first);
        }

        while(!pq.empty()) {

            int start = pq.top();

            // Try forming sequence
            for(int i = 0; i < groupSize; i++) {

                int card = start + i;

                // Missing card
                if(freq[card] == 0) {
                    return false;
                }

                freq[card]--;

                // Remove from heap when exhausted
                if(freq[card] == 0) {

                    pq.pop();
                }
            }
        }

        return true;
    }
};