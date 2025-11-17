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
	function<bool(int)> isbalance(int in){
		vector<int> count(10,0);
		while(in>0){
			count[in%10]++;
			in /=10;
		}
		for(int i = 0;i<=9;i++){
			if(count[i]>0 && count[i]!=i) return false; 
		}
		return true;
	};
	for(int i = n+1; i<= 1666666;i++){
		if(isbalance(i)){
			return i;
		}
	}
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
