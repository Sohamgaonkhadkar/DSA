class Solution{
public:
    int minimumMultiplications(vector<int> &arr,
                               int start, int end) {
                
        vector<int> dist(100000, 1e9);
        queue<int> q;
        dist[start] = 0;
        q.push(start);

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int num : arr) {
                int newNode = (node * num) % 100000;

                if(dist[node] + 1 < dist[newNode]) {
                    dist[newNode] = dist[node] + 1;

                    if(newNode == end)
                        return dist[newNode];

                    q.push(newNode);
                }
            }
        }

        return -1;
    }
};
