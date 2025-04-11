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
	vector<int> nums={5,2,5,4,5};
	int k = 2;
	int n = nums.size();
	sort(nums.begin(), nums.end());
	bool check = true;
	for(int i =0;i< n;i++) if( nums[i]< k) check = false;
	if(check==false){
		cout<<"-1"<<endl;
		return;
	}
	int right = n-1;
	int result =0;

	for(int i = n-1;i>=0;i--){
		if(nums[i]!=nums[right]){
			right = i;
			result += 1;
			continue;
		}
		if(nums[right]==k) break;
	}
	if(nums[0]>k) result++;
	cout<< result <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
