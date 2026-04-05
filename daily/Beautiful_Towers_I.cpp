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
	vector<int> heights={5,3,4,1,1};
        int n = heights.size();

	stack<pair<int,int>> ri;
	vector<long long> prefix(n,0);
	vector<long long> t_prefix(n,0);
	for(int i =n-1;i>=0;i--){
		int count =1;
		long long temp = 0;
		while(!ri.empty() && heights[ri.top().first]>= heights[i]){
			 temp+= (long long)(heights[i] - heights[ri.top().first])*ri.top().second;
			 temp+= prefix[ri.top().first];
			 count+= ri.top().second;
			 ri.pop();
		}
		prefix[i] = temp;
		t_prefix[i] = temp;
		if(!ri.empty()) t_prefix[i] += t_prefix[ri.top().first];
		ri.push({i,count});
	}
	stack<pair<int,int>> le;
	vector<long long> suffix(n,0);
	vector<long long> t_suffix(n,0);
	for(int i = 0;i< n;i++){
		int count = 1;
		long long temp = 0;
		while(!le.empty() && heights[le.top().first]>= heights[i]){
			temp+=(long long)(heights[i] - heights[le.top().first])*le.top().second;
			temp+= suffix[le.top().first];
			count+= le.top().second;
			le.pop();
		}
		suffix[i] = temp;
		t_suffix[i] = temp;
		if(!le.empty()) t_suffix[i]+= t_suffix[le.top().first];
		le.push({i,count});
	}
	long long res = LLONG_MIN;
	long long sum = 0;
	for(int i = 0;i< n;i++) sum+=heights[i];
	for(int i =0;i< n;i++){
		res = max(res, sum + (t_prefix[i] + t_suffix[i]));
	}
	return res;	

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
