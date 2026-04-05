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
	string s1;
	string s2;

	int n = s1.size();

	vector<int> even1(26,0), even2(26,0);
	vector<int> odd1(26,0), odd2(26,0);
	for(int i = 0;i< n;i++){
		if(i%2==0){
			even1[s1[i]-'a']++;
			even2[s2[i]-'a']++;
		} else {
			odd1[s1[i]-'a']++;
			odd2[s2[i]-'a']++;
		}
	}
	for(int i = 0;i<26;i++){
		if((even1[i]!=even2[i]) || (odd1[i]!=odd2[i])) return false;
	}
	return true;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
