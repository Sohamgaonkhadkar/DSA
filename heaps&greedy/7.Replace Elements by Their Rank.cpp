class Solution {
public:

    vector<int> replaceWithRank(vector<int>& arr) {

        int n = arr.size();

        priority_queue<
            int,
            vector<int>,
            greater<int>
        > pq;

        // Push all elements
        for(int num : arr) {
            pq.push(num);
        }

        unordered_map<int,int> mp;

        int rank = 1;

        while(!pq.empty()) {

            int top = pq.top();
            pq.pop();

            // Assign rank only first time
            if(mp.find(top) == mp.end()) {

                mp[top] = rank;
                rank++;
            }
        }

        // Replace with rank
        for(int i = 0; i < n; i++) {

            arr[i] = mp[arr[i]];
        }

        return arr;
    }
};

//-2=
class Solution {
public:

    vector<int> replaceWithRank(vector<int>& arr) {

        int n = arr.size();

        priority_queue<
            int,
            vector<int>,
            greater<int>
        > pq;

        // Push all elements
        for(int num : arr) {
            pq.push(num);
        }

        unordered_map<int,int> mp;

        int rank = 1;

        while(!pq.empty()) {

            int top = pq.top();
            pq.pop();

            // Assign rank only first time
            if(mp.find(top) == mp.end()) {

                mp[top] = rank;
                rank++;
            }
        }

        // Replace with rank
        for(int i = 0; i < n; i++) {

            arr[i] = mp[arr[i]];
        }

        return arr;
    }
};