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
	int nums1;
	int nums2;
	int res = 0;
	for(int item = nums1; item <=nums2; item ++){
		int pre = -1, mid = -1, next = -1;
		int count = 0;
		int temp = item;
		while(temp>0){
			count++;
			pre = mid;
			mid = next;
			next = temp%10;
			temp/=10;
			if(count>=3){
				if((mid > pre && mid > next) || (mid <pre && mid < next)){
					res++;
				}
			}
		}
	}
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
