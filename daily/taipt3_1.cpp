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
 
https://leetcode.com/problems/put-marbles-in-bags/description/?envType=daily-question&envId=2025-03-31 

IDEA : split sequence to seperate subsequence (k) 
=> each bag contain a subsequence
* if we implement by DP we have define f[i][j] : i - last ilement; j - index of bag, it will cost O(n*n) times ==> LTE
* so have to approach by a different way :
* 	+ we observe that the last item and the first item of two subsequence which lie consecutively to each orther is always be added to the result
* 	+ so we can choose k pairs of last-first from n-1 pairs and form  max-cost and min-cost
* => so get result
* preprocess : calculate all all sum between two adjacent element then store in a max-heap, min-heap
* main algorithm : for a k-loop we plus mxh.top()- mnh.top() to the result;
*/
void solve(){
	vector<int> weights;
	int k;
	int n = weights.size();
	priority_queue<long long,vector<long long>> mxh;
	priority_queue<long long, vector<long long>, greater<long long>> mnh;

	for(int i =;i<n-1;i++){
		mxh.push(weights[i] + weights[i+1]);
		mnh.push(weights[i] + weights[i+1]);
	}

	long long result = 0;

	while(k--){
		result += mxh.top() - mnh.top();
		mxh.pop();
		mnh.pop();
	}
	cout<< result;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
