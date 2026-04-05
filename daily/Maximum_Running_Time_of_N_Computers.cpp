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
	int n=2;
	vector<int> batter={1,1,1,1};
	int m = batter.size();
	
	sort(batter.begin(), batter.end());
	long long left = 0, right =0;
	for(int i = 0;i< m;i++) right+= batter[i];
	
	
	while(left<= right){
		long long mid = ( left + right)/2;
		int count = 0;

		long long remain = 0;
		for(int i = 0;i< m;i++){
			if(remain+ batter[i]<mid) remain+=batter[i];
			else {
				count++;
				remain = remain + batter[i] - mid;
			}
		}
		if(count>=n) left = mid+1;
		else right = mid-1;
	}
	cout<< right<<endl;


}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
