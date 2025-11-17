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
	vector<int> nums;
	int k;
	int n = nums.size();

	int left =2, int right = n/2;

	while(left<= right){
		int mid = ( left + right)/2;;
		bool flag = false;
		int pre =0;
		int l = 0;
		int count = 1;
    		if(mid==1) flag =  true;
		for(int i = 1;i< n;i++){
			if(nums[i]<= nums[i-1]){
				l = i;
				pre = count;
				count = 1;
				continue;
			}
			count++;

		if((count>=k && pre >=k) || count>=2*k) flag =  true;
		}
	if(flag) left = mid + 1;
	else right = mid - 1;
	}
	cout<< right <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
