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
	vector<char> tasks= {'A','A','A','B','B','B'};
	int n= 3;
	int sz= tasks.size();
	vector<int> count(26,0);
	for(int i  =0;i<sz;i++){
		count[tasks[i] - 'A']++;
	}
	priority_queue<int> pq;
	for(int i =0;i< 26;i++){
		if(count[i]>0){
			pq.push(count[i]);
		}
	}
	int dis = n + 1;
	int res = 0;
	while(!pq.empty()){
		vector<int> store;
		int count = dis;
		int temp = 0;
		while(count>0 && pq.size()>0){
			store.push_back(pq.top()-1);
			pq.pop();
			count--;
			temp++;
		}

		for(int i =0;i< store.size();i++){
			if(store[i]>0){
				pq.push(store[i]);
			}
		}
		if(pq.size()>0) res+=dis;
		else if(temp>0) res+= temp;

	}
	cout<< res <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
