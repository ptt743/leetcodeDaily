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
	vector<int> citations={};
	int n = citations.size();
	int left = 0, right = n-1;
	while(left<=right){
		int mid = (left + right)/2;
		if(citations[mid]>= (n-mid)) right = mid-1;
		else left = mid+1;
	}
	cout<< n -left<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
