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
	string s = "rur";
	int n = s.size();
	vector<int> count(26, 0);
	for(int i =0;i< n;i++) count[s[i] - 'a']++;
	int limit = (n+1)/2;
	string temp ="";
	for(int i = 0;i< limit;i++){
		for(int j = 0;j<26;j++){
			if(count[j]>=2){
				count[j]-=2;
				temp+=(char)('a' + j);
				break;
			}
			if(n%2!=0 && i==limit - 1 && count[j]>=1){
				count[j]--;
				temp +=( char)('a' + j);
				break;
			}
		}
	}
	int len = temp.size();
	if( n%2!=0) len--;
	string second = temp.substr(0,len);
	reverse(second.begin(), second.end());
	string result = temp + second;
	cout<< result<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
