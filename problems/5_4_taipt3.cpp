#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<map>
#include<unordered_map>
#include<cmath>
#include<functional>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/

struct tweet {
    int id;
    int ts;
};

struct option {
    bool operator()(tweet a, tweet b) {
        return a.ts < b.ts;
    }
};

class Twitter {
public:
    Twitter() : time(0) {}

    void postTweet(int userId, int tweetId) {
        time++;
        tweet tw = {tweetId, time};
        tweets[userId].push_back(tw);
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<tweet, vector<tweet>, option> pq;
        vector<int> users = {userId};

        if (follow.count(userId)) {
            users.insert(users.end(), follow[userId].begin(), follow[userId].end());
        }

        for (int user : users) {
            for (const tweet &tw : tweets[user]) {
                pq.push(tw);
            }
        }

        vector<int> res;
        int count = 10;
        while (count > 0 && !pq.empty()) {
            res.push_back(pq.top().id);
            pq.pop();
            count--;
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        follow[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        follow[followerId].erase(followeeId);
    }

private:
    int time;
    unordered_map<int, unordered_set<int>> follow;
    unordered_map<int, vector<tweet>> tweets;
};

void solve(){
		
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
