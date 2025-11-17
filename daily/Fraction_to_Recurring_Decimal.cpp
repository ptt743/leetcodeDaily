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
    	long long nume = (long long)numerator;
    	long long deno = (long long)denominator;
	function<long long(long long,long long)> gcd=[&](long long a, long long b){
		while(b!=0){
			long long r = a%b;
			a = b;
			b = r;
		}
		return a;
	};

	long long k = gcd(nume, deno);
	nume/=k;
	deno/=k;
	string ans ="";
	if(nume*deno<0) ans+="-";
	nume = abs(nume);
	deno = abs(deno);
	ans += to_string(nume/deno);
	if(nume%deno!=0) ans+=".";
	long long r = nume%deno;

	long long temp = deno;
	while(temp%2!=0) temp/=2;
	while(temp%5!=0) temp/=5;
	bool fintDecimal = (temp==1);

	unordered_map<long long, int> mp;
	string frac = "";
	for(int i =0;r!=0;i++){
		if(!fintDecimal){
			auto it = mp.find(r);
			if(it!=mp.end()){
				frac.insert(mp[r],"(");
				frac+=')';
				break;
			}
			mp[r] = i;
		}
		r*=10;
		frac += ('0' + r/deno);
		r%=deno;
	}
	string res = ans + frac;
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
