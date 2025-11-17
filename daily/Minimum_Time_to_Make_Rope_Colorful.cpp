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
	string colors="abaac";

	vector<int> neededTime={1,2,3,4,6};
	int n = colors.size();
	int total = 0;
	for(int item : neededTime) total += item;

	int left = 0;
	int temp = 0;
	for(int i = 0;i<=n;i++){
		if(i==n || colors[i]!=colors[left]){
			total -= temp;
			temp = 0;
			left = i;
		}
		if(i<n)temp = max(temp, neededTime[i]);
	}
	cout<< total <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
