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
	string moves;
	int n = moves.size();
	int l = 0;
	int r = 0;
	int bl = 0;
	for(char item : moves){
		if(item =='L') l++;
		else if( item == 'R') r++;
		else bl++;
	}
	return abs( l - r) + bl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
