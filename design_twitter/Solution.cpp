#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

struct Tweet {
    int time;
    int twtID;
    Tweet(int time, int twtID) : time(time), twtID(twtID) {}
};

struct CompareTweet {
    bool operator() (const Tweet& t1, const Tweet& t2) const{
        return t1.time < t2.time;
    }
};

class Twitter {
private:
    // record tweets time
    int tweetsNum;
    // map<userId, Tweet>
    unordered_map<int, vector<Tweet>> allTweets;
    // map<userId, followings>
    unordered_map<int, unordered_set<int>> followRelations;
    
public:
    /** Initialize your data structure here. */
    Twitter() {
        tweetsNum = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if (allTweets.find(userId) == allTweets.end()) {
            // can't find this user
            allTweets[userId] = vector<Tweet>();
        }
        Tweet newTwt(tweetsNum++, tweetId);
        allTweets[userId].push_back(newTwt);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> top10News;
        // construct a priority queue
        priority_queue<Tweet, vector<Tweet>, CompareTweet> topNewsQueue;
        
        // get self tweets
        vector<Tweet> selfTwts = allTweets[userId];
        // get tweets in time order
        int temp_selfTwts_size = selfTwts.size();
        for (int i = temp_selfTwts_size-1; i >= 0 && i >= temp_selfTwts_size-10; i--) {
            topNewsQueue.push(selfTwts[i]);
        }
        
        // get his following users list
        unordered_set<int> followings = followRelations[userId];
        for (auto followingUser : followings) {
            vector<Tweet> friendTwts = allTweets[followingUser];
            // get tweets in time order
            int temp_friendTwts_size = friendTwts.size();
            for (int i = temp_friendTwts_size-1; i >= 0 && i >= temp_friendTwts_size-10; i--) {
                topNewsQueue.push(friendTwts[i]);
            }
        }
        
        // get 10 tweets of every following users
        int temp_topNewsQueue_size = topNewsQueue.size();
        // pop out according in time order
        for (int i = 0; i < 10 && i < temp_topNewsQueue_size; i++) {
            top10News.push_back(topNewsQueue.top().twtID);
            topNewsQueue.pop();
        }
        return top10News;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followeeId == followerId) {
            return;
        }
        if (followRelations.find(followerId) == followRelations.end()) {
            followRelations[followerId] = unordered_set<int>();
        }
        followRelations[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId || followRelations.find(followerId) == followRelations.end()) {
            return;
        }
        followRelations[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */

int main(){
    //["Twitter","postTweet","getNewsFeed","follow","postTweet","getNewsFeed","unfollow","getNewsFeed"]
    //[[],[1,5],[1],[1,2],[2,6],[1],[1,2],[1]]
    Twitter test;
    test.postTweet(1,5);
    auto res1 = test.getNewsFeed(1);
    test.follow(1, 2);
    test.postTweet(2, 6);
    auto res2 = test.getNewsFeed(1);
    test.unfollow(1, 2);
    auto res3 = test.getNewsFeed(1);
    return 0;
}
