#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<cmath>
#include<functional>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
void solve(){
	vector<int> height={1,8,6,2,5,4,8,3,7};
	int n = height.size();
	int left = 0, right = n-1;
	int ans = 0;
	while(left<=right){
		ans = max(ans, (right - left)* min(height[right],height[left]));
		if(height[left]> height[right]) right--;
		else left++;
	}
	cout<< ans<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
