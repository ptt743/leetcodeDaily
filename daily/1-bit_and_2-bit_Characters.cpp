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
	vector<int> bits;
	int n = bits.size();
	int index =0;
	bool check= true;
	while(index<n){
		if(bits[index]==1){
			if(index== n-2 || index == n-1) return false;
			index+=2;
		}
		if(bits[index]==0) index+=1;

	}
	return check;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
