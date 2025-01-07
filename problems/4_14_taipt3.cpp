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
	string senate="RDD";
	int n = senate.size();
	queue<int> qr, qd;
	for(int i =0;i< n;i++){
		if(senate[i]=='D') qd.push(i);
		else qr.push(i);
	}
	while(qr.size()>0 && qd.size()>0){\
		int a = qr.front();
		int b = qd.front();
		qr.pop();
		qd.pop();
		if(a < b){
			qr.push(a + n);
		} else {
			qd.push(b + n);
		}
	}
	if(qd.size()> qr.size()) return "Dire";
	return "Radiant";
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}		
