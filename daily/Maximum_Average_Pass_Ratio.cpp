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
	vector<vector<int>> classes;
	int extra;

	int n = classes.size();

	struct node{
		int pass;
		int total;
		double ratio;
	};
	struct compare{
		bool operator()(const node&a, const node& b){
			return a.ratio < b.ratio;
		}
	};
	priority_queue<node, vector<node>, compare> pq;
	for(int i =0;i< n;i++){
		double a = classes[i][0];
		double b = classes[i][1];
		pq.push({(int)a, (int)b, (a+1)/(b+1) - a/b});
	}
	while(extra>0){
		node top = pq.top();
		pq.pop();
		top.pass++;
		top.total++;
		top.ratio = (double)(top.pass+1)/(top.total+1) - (double)(top.pass/top.total);
		pq.push(top);
		extra--;
	}
	double totalRatio = 0;
	while(!pq.empty()){
		node top = pq.top();
		pq.pop();
		totalRatio += (double)top.pass/top.total;
	}
	cout<< totalRatio/ n <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
