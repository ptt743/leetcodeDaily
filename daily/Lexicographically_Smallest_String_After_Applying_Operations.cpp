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
	string s;
	int a;
	int b;
	int n = s.size();
	
	int g = gcd(b,n);
	strig res  = s;
	string s = s + s;

	function<void(string&, int)> add=[&](string& t, int start){
		int minVal = 10, time =0;
		for(int i  =0;i< 10;i++){
			int temp = ((t[start]-'0') + i*a)%10;
			if(temp<minVal){
				minVal = temp;
				time = i;
			}
		}
		for(int i =0; i< n;i++) t[i] = '0' + ( (t[i]-'0') + time*a)%10;
	};
	
	for(int i =0;i< n;i+= g){
		string t = s.substr(i,n);
		add(t, 0);
		if(b%2)
			add(t,1);
		res = min(res, t);
	}
	cout<< res <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
