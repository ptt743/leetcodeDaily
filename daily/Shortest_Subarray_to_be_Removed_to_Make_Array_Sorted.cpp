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
	vector<int> arr;
        int n = arr.size();
	vector<int> lastIndex = vector<int>(n,0);

	for(int i= n-1;i>=0;i--){
		if( i== n-1 || ( arr[i] > arr[i+1])){
			lastIndex[i] = i;
			continue;
		}
		lastIndex[i] = lastIndex[i+1];
	}
	int left = 0, right = n-1;
	while(left<=right){
		int mid = ( left + right)/2;
		bool check = false;
		for(int i = 0;i<=n-mid;i++){
			if(i==n-mid && lastIndex[0]>=i-1){
				check = true;
               			break;
			}
		    	if(i==0 && lastIndex[i+ mid]>= n-1){
				check = true;
				break;
		    	}
			if(lastIndex[0]>=i-1 && (lastIndex[i+mid]>=n-1) && arr[i-1] <= arr[i+ mid])
				check = true;
		}
		if(check) right = mid-1;
		else left = mid+1;
	}
	return left;	
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
