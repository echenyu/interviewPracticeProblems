#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {}
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        createUser(userId); 
        messages.insert(messages.begin(), tweetId); 
        messageToUserMap[tweetId] = userId; 
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        createUser(userId); 
        unordered_set<int> followers = userMapping[userId].followers; 
        int count = 0; 
  
        for(auto i : messages) {
            if(count == 10) break;
            if(followers.find(messageToUserMap[i]) != followers.end()) {
                res.push_back(i); 
                count++;
            }
        }
  
        return res; 
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        createUser(followerId); 
        userMapping[followerId].followers.insert(followeeId); 
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) return; 
        if(userMapping.find(followerId) != userMapping.end()) {
            if(userMapping.find(followeeId) != userMapping.end()) {
                userMapping[followerId].followers.erase(followeeId); 
            }
        }
    }
    
private:
    class User {
    public:
        User() {}
        unordered_set<int> followers; 
    };
    
    void createUser(int id) {
        if(userMapping.find(id) == userMapping.end()) {
            userMapping[id] = User(); 
            userMapping[id].followers.insert(id); 
        }
    }
    vector<int> messages; 
    unordered_map<int, int> messageToUserMap; 
    unordered_map<int, User> userMapping; 
};