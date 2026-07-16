class Twitter {
private:
unordered_map<int,set<int>> fmap;
unordered_map<int,vector<pair<int,int>>> tmap;
int count;
public:

    Twitter() {
        count=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tmap[userId].push_back({count++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        set<int> all=fmap[userId];
        all.insert(userId);
        priority_queue<pair<int,int>> tweets;
        vector<int> ans;
        for(int q:all){
            for(auto l:tmap[q]){
                tweets.push(l);
            }
        }
        int a=10;
        while(a-- && !tweets.empty()){
            auto lm=tweets.top();
            tweets.pop();
            ans.push_back(lm.second);
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        fmap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        fmap[followerId].erase(followeeId);
    }
};
