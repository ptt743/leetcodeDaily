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
	int l = 0;
	vector<int> check(3,0);
	function<bool()> che=[&]{
		return check[0] >0 && check[1]>0 && check[2]>0;
	};
	int count = 0;
	for(int i = 0; i< n;i++){
		check[s[i]-'a']++;
		while(che()){
			check[s[l]-'a']--;
			l++;
		}
		count+=l;
	}
	return count;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
