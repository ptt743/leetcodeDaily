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
	vector<vector<int>> languages;
	vector<vector<int>> friendships;
	unordered_set<int> st;
        for(vector<int>& item : friendships ){
		unordered_map<int,bool> mp;
		for(int lan : languages[item[0]-1]){
			mp[lan] = true;
		}
		bool check = false;
		for(int lan : languages[item[1]-1]){
			if(mp[lan]){
				check = true;
				break;
			}
		}
		if(!check){
			st.insert(item[0]);
			st.insert(item[1]);
		}
	}
	vector<int> count(n+1,0);
	int maxVal = 0;
	for(int uid: st){
		for(int lan: languages[uid-1]){
			count[lan]++;
			maxVal = max(maxVal, count[lan]);
		}
	}
	return st.size() - maxVal;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
