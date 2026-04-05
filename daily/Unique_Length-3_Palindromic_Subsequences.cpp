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
	int n = s.size();

	vector<vector<int>> countleft = vector<int>(n,vector<int>(26,0));
	for(int i = 0;i< n;i++){
		if(i>0) countleft[i] = countleft[i-1];
		countleft[i][s[i]-'a']++;
	}
	vector<int> countright = vector<int>(26,0);
	vector<vector<bool>> check(26,vector<int>(26,false));
	vector<int> res(26,0);
	countright[s[n-1]-'a']++;
	for(int i = n-2;i>0;i--){
		for(int j = 0;j<26;j++){
			if(countleft[i-1][j]>0 && countright[i+1][j]>0 && check[s[i] - 'a'][j]==false){
				res[s[i]-'a']++;
				check[s[i]-'a'][j] = true;
			}
		}
	}
	int result = 0;
	for(int i = 0;i< 26;i++) result+= res[i];
	return result;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
