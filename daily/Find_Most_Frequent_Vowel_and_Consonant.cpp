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
	vector<int> count(26,0);
	for(char item : s){
		count[item - 'a']++;
	}
	int maxv = 0;
	int maxc = 0;
	for(int i =0;i< 26;i++){
		if(i== 'a' -'a' || i == 'e' - 'a' || i == 'u' - 'a' || i == 'o' - 'a' || i == 'i' - 'a'){
			maxv = max(maxv, count[i]);
		} else {
			maxc = max(maxc, count[i]);
		}
	}
	return maxc + maxv;
	
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
