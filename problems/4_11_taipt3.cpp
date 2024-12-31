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
struct point{
	long long time;
	int count;
	int workertime;
	int index;
};
struct compare{
	bool operator()(point a, point b){
		return a.time > b.time;
	}	
};
void solve(){
	int mountainHeight = 5;
	vector<int> workertimes = {1,7};
	priority_queue<point, vector<point>, compare> minheap;
	int n = workertimes.size();
	vector<long long> times(n,0);
	for(int i =0;i< n;i++){
		minheap.push({workertimes[i], 1, workertimes[i], i});
	}
	long long result = 0;
	while(mountainHeight>0){
		point top = minheap.top();
		minheap.pop();
		result = max(result, top.time);
		mountainHeight--;
		minheap.push({top.time + (long long)top.workertime*(top.count+1), top.count+1, top.workertime, top.index});
	}
	cout<< result <<endl;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
