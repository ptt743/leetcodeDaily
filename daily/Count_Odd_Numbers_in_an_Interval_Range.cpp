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
	int low;
	int high;

	// 0 1 2 3 4 5
	
	int left = low/2;
	if(low%2!=0) left++;
	int right = high/2;
	if(high%2!=0) right++;
	int result = right - left;
	if(low%2!=0) result+=1;
	return result;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
