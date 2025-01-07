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
	vector<int> deck={1,1000};
	int n = deck.size();
	// 2 13 3 11 5 17 7
	// 2 3 11 5 17 7 13
	// 2 3 5 17 7 13 11
	// 2 3 5 7 13 11 17
	// 2 3 5 7 11 17 13
	// 2 3 5 7 11 13 17
	// 
	//
	sort(deck.begin(), deck.end());
	deque<int> dq;
	dq.push_back(deck[n-1]);
	int left = n-1;
	while(left > 0){
		int temp = dq.back();
		dq.pop_back();
		dq.push_front(temp);
		left--;
		dq.push_front(deck[left]);
	}
	vector<int> res;
	while(!dq.empty()){
		res.push_back(dq.front());
		dq.pop_front();
	}
	return res;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
