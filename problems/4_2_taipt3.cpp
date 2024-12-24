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
	vector<int> nums={};
	int n = nums.size();
	int left =1, right =n-1;
	while(left<=right){
		int mid = (left + right)/2;
		int count = 0;
		for(int i =0;i< n;i++){
			if(nums[i] <= mid){
				count++;
			}
		}
		if(count<=mid) left  = mid+1;
		else right = mid-1;
	}
	cout<< left <<endl;
}

void solve2(){
	vector<int> nums ={1,3,4,1,2};
	int n = nums.size();
	
	int slow = 0;
        int fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
	cout<< slow<<endl;


}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve2();
    return 0;
}
