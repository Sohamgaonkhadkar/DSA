class Solution {//bfs won't work memory limit exceeded
public:
    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList)
    {
        unordered_set<string> st(wordList.begin(),
                                 wordList.end());

        vector<vector<string>> ans;

        queue<vector<string>> q;

        q.push({beginWord});

        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);

        int level = 1;
        int shortest = INT_MAX;

        while(!q.empty())
        {
            vector<string> path = q.front();
            q.pop();

            if(path.size() > level)
            {
                level = path.size();

                for(auto &word : usedOnLevel)
                    st.erase(word);

                usedOnLevel.clear();

                if(level > shortest)
                    break;
            }

            string word = path.back();

            if(word == endWord)
            {
                if(ans.empty())
                {
                    shortest = path.size();
                    ans.push_back(path);
                }
                else if(path.size() == shortest)
                {
                    ans.push_back(path);
                }
            }

            for(int i = 0; i < word.size(); i++)
            {
                string temp = word;

                for(char c = 'a'; c <= 'z'; c++)
                {
                    temp[i] = c;

                    if(st.find(temp) != st.end())
                    {
                        vector<string> newPath = path;

                        newPath.push_back(temp);

                        q.push(newPath);

                        usedOnLevel.push_back(temp);
                    }
                }
            }
        }

        return ans;
    }
};-- wont woek
//-dfs
class Solution {
public:
    
    vector<vector<string>> ans;
    unordered_map<string, int> level;

    void dfs(string word, string beginWord,
             vector<string>& path)
    {
        if(word == beginWord)
        {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        int steps = level[word];

        for(int i = 0; i < word.size(); i++)
        {
            char original = word[i];

            for(char c = 'a'; c <= 'z'; c++)
            {
                word[i] = c;

                if(level.find(word) != level.end() &&
                   level[word] + 1 == steps)
                {
                    path.push_back(word);
                    dfs(word, beginWord, path);
                    path.pop_back();
                }
            }

            word[i] = original;
        }
    }

    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList)
    {
        unordered_set<string> st(wordList.begin(),
                                 wordList.end());

        queue<string> q;

        q.push(beginWord);

        level[beginWord] = 0;

        st.erase(beginWord);

        while(!q.empty())
        {
            string word = q.front();
            q.pop();

            int steps = level[word];

            if(word == endWord)
                break;

            for(int i = 0; i < word.size(); i++)
            {
                char original = word[i];

                for(char c = 'a'; c <= 'z'; c++)
                {
                    word[i] = c;

                    if(st.find(word) != st.end())
                    {
                        q.push(word);

                        level[word] = steps + 1;

                        st.erase(word);
                    }
                }

                word[i] = original;
            }
        }

        if(level.find(endWord) == level.end())
            return {};

        vector<string> path;

        path.push_back(endWord);

        dfs(endWord, beginWord, path);

        return ans;
    }
};