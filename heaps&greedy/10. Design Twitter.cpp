class Twitter {
public:

    int timer;

    unordered_map<int, unordered_set<int>> following;

    unordered_map<int, vector<pair<int,int>>> tweets;

    Twitter() {
        timer = 0;
    }
    
    void postTweet(int userId, int tweetId) {

        tweets[userId].push_back({timer++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {

        vector<pair<int,int>> allTweets;

        // user's own tweets
        for(auto &tweet : tweets[userId]) {
            allTweets.push_back(tweet);
        }

        // followed users tweets
        for(int followee : following[userId]) {
            for(auto &tweet : tweets[followee]) {
                allTweets.push_back(tweet);
            }
        }

        // latest first
        sort(allTweets.begin(), allTweets.end(), greater<>());

        vector<int> ans;

        for(int i = 0; i < min(10, (int)allTweets.size()); i++) {
            ans.push_back(allTweets[i].second);
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {

        if(followerId == followeeId)
            return;

        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {

        following[followerId].erase(followeeId);
    }
};