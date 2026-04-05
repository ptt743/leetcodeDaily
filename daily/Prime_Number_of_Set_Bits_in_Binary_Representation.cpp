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
	int left;
	int right;
	function<bool(long long)> isPrime=[&](long long n) {
	    if (n <= 1) return false;
	    if (n <= 3) return true;
	    if (n % 2 == 0 || n % 3 == 0) return false;

	    for (long long i = 5; i * i <= n; i += 6) {
		if (n % i == 0 || n % (i + 2) == 0) {
		    return false;
		}
	    }
	    return true;
	};
	int res = 0;
	for(int i = left; i <=right;i++){
		int temp = i;
		int count = 0;
		while(temp!=0){
			count+= temp%2;
			temp/=2;
		}
		if(isPrime(count)) res++;
	}
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
