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
	int n = 2;
	vector<vector<int>> meetings = {{43,44},{34,36},{11,47},{1,8},{30,33},{45,48},{23,41},{29,30}};
	
	sort(meetings.begin(), meetings.end());
	int m = meetings.size();

	int maxTime = 0;
	for(int i =0;i<m;i++){
		maxTime = max(meetings[i][1],maxTime);
	}
	int left = 0;
	vector<int> count(n+1, 0);
	set<int> st;
	for(int i =0;i<n;i++){
		st.insert(i);
	} 
	priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>>pq;
	for(int i =0;left<m;i++){
		while(!pq.empty() && pq.top().first<=i){
			pair<int,int> top = pq.top();
			pq.pop();
			st.insert(top.second);
		}	
		while(left<m && meetings[left][0]<= i && !st.empty()){
			pq.push({i + (meetings[left][1] - meetings[left][0]), *st.begin()});
			count[*st.begin()]++;
			cout<< *st.begin()<<" "<< i + (meetings[left][1] - meetings[left][0])<<endl;
			st.erase(*st.begin());
			left++;
		}
		
	}
	int result =0;
	int val = 0;
	for(int i =0;i<n;i++)
		if(count[i]> val) val = count[i], result = i;
	cout<< result <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
