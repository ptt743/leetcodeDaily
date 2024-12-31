#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<cmath>
#include<functional>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
void solve(){
	int n = 10, m = 12;
	vector<bool> isprime(1e4+5, 1);
	isprime[0] =0;
	isprime[1] = 0;
	for(int i =2;i<1e4+5;i++){
		if(isprime[i]){
			for(int j = i* 2;j<1e4+5;j+=i){
				isprime[j] = 0;
			}
		}
	}
	if(isprime[n] || isprime[m]){
		cout<<"-1"<<endl;
	}
	vector<long long> dist(1e4+1, 1e9);
	auto dijkstra = [&](){
		priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
		pq.push({n,n});
		dist[n] = n;
		while(!pq.empty()){
			pair<int,int> top= pq.top();
			int sum = top.first;
			int str = top.second;
			pq.pop();
			string currStr = to_string(str);
			int sz = currStr.size();
			for( int i =0;i< sz;i++){
				string curr = currStr;
				if(curr[i] !='0' && !(i==0 && curr[i]=='1')){
					curr[i]--;
					int value = stoi(curr);
					if(sum + value < dist[value] && !isprime[value]){
						pq.push({sum + value, value});
						dist[value] = sum + value;
					}
					curr[i]++;
				}
				if(curr[i] !='9'){
					curr[i]++;
					int value = stoi(curr);
					if(sum + value< dist[value] && !isprime[value]){
						pq.push({sum+ value, value});
						dist[value] = sum + value;
					}
					curr[i]--;
				}
			}
		}
	};
	dijkstra();
	cout<< dist[m]<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
