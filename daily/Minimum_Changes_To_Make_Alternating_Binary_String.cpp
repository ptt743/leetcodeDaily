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
	string s;
	int n = s.size();
	int count1 = 0;
	for(int i =0;i<n;i++){
		if(i%2==0 && nums[i]!='1')count1++;
		else if(i%2!=0 && nums[i]!='0')count1++;
	}
	int count2 =0;
	for(int i =0;i<n;i++){
		if(i%2==0 && nums[i]!='0')count2++;
		else if(i%2!=0 && nums[i]!='1')count2++;
	}
	return min(count1, count2);
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
