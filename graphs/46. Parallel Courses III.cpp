class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
         vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        int maxTime = 0;
        for(auto &p : relations)
        {
            int course = p[0];
            int prereq = p[1];

            adj[prereq].push_back(course);
            indegree[course]++;
        }
        priority_queue<pair<int,int>,
        vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(int i=0;i<n;i++)
        {
            if(indegree[i] == 0)
                pq.push({time[i], i});
        }
        while(!pq.empty())
        {
            auto [t, course] = pq.top();
            pq.pop();
            maxTime = max(maxTime, t);
            for(int nextCourse : adj[course])
            {
                indegree[nextCourse]--;
                if(indegree[nextCourse] == 0)
                {
                    pq.push({t + time[nextCourse], nextCourse});
                }
            }
        }
        return maxTime;
    }
};
//-2
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {

        vector<vector<int>> adj(n+1);
        vector<int> indegree(n+1,0);

        for(auto &p : relations)
        {
            int course = p[0];
            int prereq = p[1];

            adj[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        vector<int> finishTime(n+1,0);

        // courses with no prerequisite
        for(int i=1;i<=n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                finishTime[i] = time[i-1];
            }
        }

        int ans = 0;

        while(!q.empty())
        {
            int course = q.front();
            q.pop();

            ans = max(ans, finishTime[course]);

            for(int next : adj[course])
            {
                // update maximum time needed before starting next course
                finishTime[next] = max(
                    finishTime[next],
                    finishTime[course] + time[next-1]
                );

                indegree[next]--;

                if(indegree[next]==0)
                {
                    q.push(next);
                }
            }
        }

        return ans;
    }
};