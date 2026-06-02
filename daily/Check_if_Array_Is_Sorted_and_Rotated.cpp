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
	int size = 2*n;
	vector<int> temp(size,0);
	for(int i = 0; i< size; i++){
		temp[i] = arr[i%n];
	}
	int left =0;
	bool check = false;
	for(int i = 1;i< size;i++){
		if(temp[i]< temp[i-1]) left = i;
		if(i - left +1>= n) return true;
	}
	return false;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
