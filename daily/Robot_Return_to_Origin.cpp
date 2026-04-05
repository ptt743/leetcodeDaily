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
	int x = 0, y = 0;
	for(int i =0;i< n;i++){
		if(moves[i]=='L') y--;
		if(moves[i]=='R') y++;
		if(moves[i]=='U') x--;
		if(moves[i]=='D') x++;
	}
	return ( x==0 && y ==0);

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
