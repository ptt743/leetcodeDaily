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
	vector<int> houses={1,5};
	vector<int> heaters={2};
	int n = houses.size();
	int m = heaters.size();

	sort(houses.begin(), houses.end());
	sort(heaters.begin(), heaters.end());

	long long left = 0, right = 1e9;
	while(left<=right){
		int mid = (int)( left + right)/2;
		int l = 0, r = 0;
		for(r;r<m;r++){
			int borderl = heaters[r] - mid;
			int borderr = heaters[r] + mid;
			while(l < n && houses[l]>= borderl && houses[l]<= borderr) l++;
		}
		if(l==n) right = mid-1;
		else left = mid+1;
	}
	cout<< left << endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
