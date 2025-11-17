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
	vector<string> bank;
	int n = bank.size();

	int pre = 0;
	int result = 0;
	for(int i = 0; i< n;i++){
		int m = bank[i].size();
		int count = 0;
		for(int j = 0;j< m;j++){
			count += bank[i][j] - '0';
		}
		result += count* pre;
		if(count !=0) pre =  count;
	}
	return result;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
