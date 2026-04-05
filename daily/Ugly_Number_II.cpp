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
	int n;
	vector<int> nums = {2,3,5};
        priority_queue<long long, vector<long long>, decltype([](long long a ,long long b){ return a > b;})> pq;

	unordered_set<long long> st;
	pq.push(1);
	st.insert(1);
	long long init = 0;
	for(int i = 1;i<=n;i++){
		init = pq.top();
		pq.pop();
		for(int item: nums){
			long long val = init * item;
			if(!st.count(val)){
				pq.push(val);
                st.insert(val);
			}
		}
	}
	return init;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
