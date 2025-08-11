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
	long long k = 67108864;
	vector<int> operations= {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	function<int(long long)> findN2=[&](long long val){
		int count = 0;
		while(val>1){
			val/=2;
			count++;
		}
		return count;
	};
	int ans = 0;
	int count=1;
	while(k>1){
		int n2 = findN2(k);
		if((1<<n2) <k ){
			n2+=1;
		}
		ans +=operations[n2-1];
		k-=(1<<(n2-1));
		cout<< k <<endl;
	}
	ans%=26;
	cout<< (char)('a'+ans) <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
