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
	int n;
	vector<int> count(10,0);
	int t = n;
	while(t>0){
		count[t%10]++;
		t/=10;
	}
	for(int i =0 ; i< 31;i++){
		int temp = (1<< i);
		vector<int> count2(10,0);
		while(temp>0){
			count2[temp%10]++;
			temp/=10;
		}
		bool check = true;
		for(int i= 0;i< 10;i++){
			if(count2[i]!=count[i]) check = false;
		}
		if( check) return true;
		else continue;
	}
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
