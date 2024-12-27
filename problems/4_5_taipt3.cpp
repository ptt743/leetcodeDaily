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
	vector<long long> f(11,1);
	vector<long long> p(11,1);
	f[0]=0;
	long long digits = 1ll;
	long long temp = 1ll;
	for(long long i = 1;i<=10;i++){
		p[i] =temp;
		temp*=10ll;

	}
	for(long long i =1;i<=10;i++){
		f[i] = f[i-1] + i*9ll*digits;
		digits*=10ll;
	}
	long long left = 1, right = 3e9;
	while(left <= right){
		long long mid = (left + right)/2;
		long long len = to_string(mid).size();
		long long result = len*(mid - p[len]+1) + f[len-1];
		if(result>= n) right = mid-1;
		else left = mid +1;
	}
	long long templ = left -1;
	string s  = to_string(templ);
	string result = to_string(left);
	long long len = s.size();
	long long pre = len*(templ - p[len] +1) + f[len-1];
	cout<< result[n - pre -1]<<endl;	



}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
