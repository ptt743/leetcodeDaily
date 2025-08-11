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
	int eventTime = 10 ;
	vector<int> startTime = {0,7,9};
	vector<int> endTime={1,8,10};

	int n = startTime.size();

	struct node{
		int start;
		int end;
		int dur;
	};

	int starting  =0;
	int ending = eventTime;
	multiset<int> durs;
	vector<node> nodes;

	for(int i =0;i< n;i++){
		int start = startTime[i] - starting;
		int end = ((i<n-1)?startTime[i+1]:eventTime) - endTime[i];
		int dur = endTime[i] - startTime[i];
		starting = endTime[i];
		nodes.push_back({start, end, dur});
		durs.insert(start);
		if(i==n-1) durs.insert(end);
	}
	int result = 0;
	for(int i =0;i< n;i++){
		result = max(result,nodes[i].start + nodes[i].end);
		auto it1  = durs.find(nodes[i].start);
		durs.erase(it1);
		auto it2 = durs.find(nodes[i].end);
		durs.erase(it2);
		if(durs.lower_bound(nodes[i].dur)!=durs.end())
			result = max(result, nodes[i].dur + nodes[i].start + nodes[i].end);
		durs.insert(nodes[i].start);
		durs.insert(nodes[i].end);
	}
	cout<< result << endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
