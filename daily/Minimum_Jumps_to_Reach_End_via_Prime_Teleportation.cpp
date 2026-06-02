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
void solve(){
	vector<int> nums;
	int n = nums.size();
	int maxValue = *max_element(nums.begin(), nums.end())+1;
	vector<int>spf (maxValue, 0);
	for(int i = 0;i< maxValue ;i++){
		spf[i] = i;
	}
	for(int i = 2; i*i < maxValue; i++){
		if(spf[i]==i){
			for(int j = i*i ; j< maxValue; j+=i){
				spf[j] = i;
			}
		}
	}

	unordered_map<int, vector<int>> mp;
	for(int i = 0;i< n;i++){
		int temp = nums[i];
		while( temp > 1){
			int p = spf[temp];
			mp[p].push_back(i);
			while(temp%p==0){
				temp/=p;
			}
		}
	}
	queue<pair<int,int>> qq;
	qq.push({0,0});
	vector<int> visited(n, false);
	visited[0] = true;
	int ans = -1;
	while(!qq.empty()){
		int front = qq.front().first;
		int dis = qq.front().second;
		int val = nums[front];
		if(front == n-1) ans = dis;
		qq.pop();
		if(front - 1>=0 && !visited[front-1]){
            visited[front-1] = true;
            qq.push({front-1, dis+1});
        }
		if(front+1 <n && !visited[front+1]){
            visited[front+1] = true;
            qq.push({front+1, dis+1});
        }
		if(mp.find(val)!=mp.end()){
			for(int item : mp[val]){
				if(!visited[item]){
                    visited[item] = true;
					qq.push({item, dis+1});
				}
			}
		}
        mp.erase(val);
	}
	return ans;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
