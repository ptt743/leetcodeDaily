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
	int k;
	string res = "";
	if(3*(1<<(n-1))<k) return "";
	int blocksize = (1<<(n-1));
	int part = (k-1)/blocksize;
	char pre = 'a' + part;
	res += pre;
	k-= blocksize * part;
	for(int i = 1;i< n;i++){
		blocksize>>=1;
		part = (k-1)/blocksize;
		char first, second;
		if(pre=='a'){
			first = 'b';
			second = 'c';
		} else if( pre =='b'){
			first = 'a';
			second = 'c';
		} else {
			first = 'a';
			second = 'b';
		}
		pre = (part==0)?first:second;
		res+=pre;
		k-= part*blocksize;
	}
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
