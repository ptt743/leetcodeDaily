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
	vector<int>nums;
	int pivot;
	int n= nums.size();
	vector<int> left, right, mid;
	for(int item : nums){
		if(item> pivot) right.push_back(item);
		else if(item<pivot) left.push_back(item);
        else mid.push_back(item);
	}
	vector<int> res;
    	for(int item:mid) left.push_back(item);
	for(int item: right) left.push_back(item);
	return left;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
