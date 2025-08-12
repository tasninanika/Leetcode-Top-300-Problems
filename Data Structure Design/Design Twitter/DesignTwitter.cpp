class Twitter {
    using Tweet = pair<int, int>;
    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, vector<Tweet>> tweets;
    int timestamp;

public:
    Twitter() : timestamp(0) {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(timestamp++, tweetId);
    }

    vector<int> getNewsFeed(int userId) {
        vector<Tweet> feed;

        for (const Tweet& tweet : tweets[userId]) {
            feed.push_back(tweet);
        }

        for (int followee : followers[userId]) {
            for (const Tweet& tweet : tweets[followee]) {
                feed.push_back(tweet);
            }
        }

        sort(feed.begin(), feed.end(), [](const Tweet& a, const Tweet& b) {
            return a.first > b.first;
        });

        vector<int> result;
        for (int i = 0; i < feed.size() && i < 10; ++i) {
            result.push_back(feed[i].second);
        }
        return result;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followers[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
