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
	vector<int> nums={3,1,4,3,2,2,4};
	int k=2;
	int n = nums.size();
	unordered_map<int,int> mp;
	int right = -1;
	long long count = 0l;
	long long result = 0l;
	for(int left = 0; left < n;left++){
		while(count<k && right< n-1){
			right++;
			int value = mp[nums[right]];
			count+=value;
			mp[nums[right]]++;
		}
		if(count>=k) result += n - right;
		int value = mp[nums[left]];
		mp[nums[left]]--;
		count-=value -1;
	}
	cout<< result<<endl;
	
}

void solve2(){
	vector<int> nums ={1,1,1,1,1};
	int k = 10;
	int n = nums.size();
	long long result  = (n-1)*n/2;
	long long count = 0;
	int left = 0;
	unordered_map<int,int> mp;
	for(int right=0;right<n;right++){
		count+=mp[nums[right]];
		mp[nums[right]]++;
		while( count>= k && left< right){
			count -= mp[nums[left]]-1;
			mp[nums[left]]--;
			left++;
			
		}
		result -= (right-left);
	}
	cout<< result <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve2();
    return 0;
}
