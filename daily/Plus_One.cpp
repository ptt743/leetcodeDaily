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
	vector<int> digits;
	int n = digits.size();
	int temp =1;
	for(int i = n-1;i>=0;i--){
		int val = digits[i]+ temp;
		if(val>=10){
			digits[i] = 0;
			temp =1;
		} else{
			digits[i] = val;
			temp = 0;
		}
	}
	if(temp ==0) return digits;
	else{
		vector<int> result = {1};
		for(int i =0;i< n;i++) result.push_back(digits[i]);
		return result;
	}
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
