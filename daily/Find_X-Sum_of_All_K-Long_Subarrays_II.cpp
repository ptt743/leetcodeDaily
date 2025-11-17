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
	vector<int> nums={3,8,7,8,7,5};
	int k = 2;
	int x = 2;
	int n = nums.size();

	set<pair<int,int>> stx;
	set<pair<int,int>> st;
	long long result = 0 ;
	function<void(pair<int,int> p)> erase=[&](pair<int,int> p){
		if(p>= *stx.begin()){
			stx.erase(p);
			result -= (long long)p.first * p.second;
			if(st.size()>0){
				pair<int,int> tranfer = * st.rbegin();
				result+= (long long)tranfer.first * tranfer.second;
				stx.insert(tranfer);
				st.erase(tranfer);
			}
		} else {
			st.erase(p);
		}
	};

	function<void(pair<int,int>)> add = [&](pair<int,int>p){
		if(stx.size()< x || p> * stx.begin()){
			stx.insert(p);
			result+= (long long)p.first* p.second;
			if(stx.size()>x){
				pair<int,int> tranfer = *stx.begin();
				result-= (long long)tranfer.first * tranfer.second;
				st.insert(tranfer);
				stx.erase(tranfer);
			}
		} else {
			st.insert(p);
		}
	};

	map<int,int> count;
	int left = 0;
	vector<long long> res;
	for(int i = 0;i< n;i++){
		if(count[nums[i]]>0){
			erase(make_pair(count[nums[i]], nums[i]));
		}
		count[nums[i]]++;
		add(make_pair(count[nums[i]], nums[i]));
		if(i>=k){
			erase(make_pair(count[nums[left]], nums[left]));
			count[nums[left]]--;
			if(count[nums[left]]>0){
				add(make_pair(count[nums[left]], nums[left]));	
			}
			left++;
		}
		if(i>=k-1) res.push_backresult);
	}
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
