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

struct compare {
	bool operator()(int a, int b){
		return a < b;
	}
};
vector<int> solve(){
	vector<vector<int>> queries={{5,5},{4,4},{3,3}};
	int k=1;
	vector<int> res;	
	int n = queries.size();
	priority_queue<int, vector<int>, compare> pq;
	for(int i =0;i< n;i++){
		pq.push(abs(queries[i][0]) + abs(queries[i][1]));
		if(pq.size()>k) pq.pop();
		if(pq.size()==k) res.push_back(pq.top());
		else res.push_back(-1);
	}
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
