class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_set<string> st(wordList.begin(), wordList.end());
        q.push(beginWord);
        int level = 1;
        while(!q.empty()) {
            int size = q.size();
            for(int i=0;i<size;i++) {
                string word = q.front();
                q.pop();
                if(word == endWord)
                    return level;
                st.erase(word);
                for(int j=0;j<word.length();j++) {
                    char original = word[j];
                    for(char c='a';c<='z';c++) {
                        if(c == original)
                            continue;
                        word[j] = c;
                        if(st.find(word) != st.end()) {
                            q.push(word);
                        }
                    }
                    word[j] = original;
                }
            }
            level++;
        }
        return 0;
    }
};