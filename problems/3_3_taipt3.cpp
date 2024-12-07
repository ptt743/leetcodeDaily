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
	int n;
	cin>> n;
	vector<string> result;

	function<void(int,string,int ,int)> rc=[&](int index, string pref,int first ,int second)->void{
		if(index == 2*n){
			result.push_back(pref);
			return;
		}
		if(second <n && second<first) rc(index+1, pref + ")",first, second+1);
		if(first<n)rc(index+1, pref + "(", first +1, second);
	};
	rc(0,"",0,0);
	for(string item: result) cout<< item <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
