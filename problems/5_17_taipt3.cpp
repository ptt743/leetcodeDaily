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
unordered_map<int,int> mp;
deque<int> dq;
int count  = 0;

void solve(){
	mp[num]++;
        dq.push_back(num);
        if(dq.size()>k){
            int front = dq.front();
            mp[front]--;
            if(mp[front]==0) mp.erase(front);
            dq.pop_front();
        }
        if(mp[value]>0 && mp.size()==1 && dq.size()==k) return true;
        return false;		
}

void solve2(){
	if(num == val) count++;
        else count = 0 ;
        return count >= n;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
