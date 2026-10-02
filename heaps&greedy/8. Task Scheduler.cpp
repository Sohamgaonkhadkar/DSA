class Solution {
public:

    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26,0);

        // Count frequencies
        for(char ch : tasks) {
            freq[ch - 'A']++;
        }

        int maxFreq = *max_element(freq.begin(), freq.end());

        int countMax = 0;

        // Count tasks having max frequency
        for(int f : freq) {

            if(f == maxFreq) {
                countMax++;
            }
        }

        return max(
            (int)tasks.size(),
            (maxFreq - 1) * (n + 1) + countMax
        );
    }
};

//-2
class Solution {
public:

    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26,0);

        // Count frequencies
        for(char ch : tasks) {
            freq[ch - 'A']++;
        }

        // Max Heap
        priority_queue<int> pq;

        for(int f : freq) {

            if(f > 0) {
                pq.push(f);
            }
        }

        // {remainingCount, readyTime}
        queue<pair<int,int>> q;

        int time = 0;

        while(!pq.empty() || !q.empty()) {

            time++;

            // Execute task
            if(!pq.empty()) {

                int cnt = pq.top();
                pq.pop();

                cnt--;

                // Still remaining
                if(cnt > 0) {

                    q.push({cnt, time + n});
                }
            }

            // Cooldown finished
            if(!q.empty() && q.front().second == time) {

                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};