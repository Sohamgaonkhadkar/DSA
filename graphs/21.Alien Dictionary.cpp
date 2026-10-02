class Solution {
public:
    string findOrder(vector<string>& dict, int K) {

        vector<vector<int>> adj(K);

        for(int i=0;i<dict.size()-1;i++)
        {
            string s1 = dict[i];
            string s2 = dict[i+1];

            int len = min(s1.size(), s2.size());

            for(int j=0;j<len;j++)
            {
                if(s1[j] != s2[j])
                {
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }

        vector<int> indegree(K,0);

        for(int i=0;i<K;i++)
        {
            for(int neigh : adj[i])
                indegree[neigh]++;
        }

        queue<int> q;

        for(int i=0;i<K;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }

        string ans="";

        while(!q.empty())
        {
            int node=q.front();
            q.pop();

            ans += char(node+'a');

            for(int neigh : adj[node])
            {
                indegree[neigh]--;

                if(indegree[neigh]==0)
                    q.push(neigh);
            }
        }

        return ans;
    }
};