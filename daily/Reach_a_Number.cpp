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
	int target;
	long long l = 1, r = abs(target);
	while(l<=r){
		long long mid = (l + r)/2;
		long long sum = ( 1+ mid)*mid/2;
		if(sum >= abs(target) ) r = mid-1;
		else l = mid +1;
	}
	long long sum = ( l +1)*l/2;
	while( ( sum- abs(target))%2!=0){
		l++;
		sum+=l;
	}
	return l;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
