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
	vector<string> nums;
	int n = nums.size();
	unordered_set<long long> st;
	for(int i =0;i< n;i++){
		long long temp = 0;
		for(int j = 0;j< n;j++){
			temp = (temp<<1)|(nums[i][j]-'0');
		}
		st.insert(temp);
	}
	long long ans = 0;
	for(long long item =0;item < 1<<n;item++){
		if(st.find(item)==st.end()){
		    ans = item;
		    break;
		}
	}
	vector<char> res;
	while(ans!=0){
		int t = ans%2;
		ans/=2;
		res.push_back('0' + t);
	}
	while(res.size()<n) res.push_back('0');
	reverse(res.begin(), res.end());
	string result = "";
	for(char item : res){
		result+=item;
	}
	return result;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
