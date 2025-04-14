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
	long long n = 4;
	long long mod = 1e9+7;
	long long result = 1;
	long long numseven = 0;
	long long numsodd = 0;
	numseven = numsodd = n/2ll;
	function<long long(long long , long long)>  power=[&](long long a, long long b) {
    		long long result = 1;
    		while (b > 0) {
        	if (b % 2 == 1) {
            		result = (result*a)%mod;
        	}
        	a *= (a*a)%mod;
        	b /= 2;
    		}
    		return result;
	};

	if(n%2!=0) numseven +=1;
	result = ( (result%mod) * ( power(5ll,numseven)%mod))%mod;
	result = ( (result%mod) * ( power(4ll,numsodd)%mod))%mod;
	
	cout<< result << endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
