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
	vector<int>& commands;
	vector<vector<int>> obstacles;		
	
	int x = 0, y = 0;
	int n = commands.size();
	vector<pair<int,int>> direc = {{-1,0}, {0,1}, {1,0},{0,-1}};
	int init = 1;
	set<pair<int,int>> st;
	int res =0;
	for(int i =0;i< obstacles.size();i++){
		st.insert({obstacles[i][0], obstacles[i][1]});
	}
	for(int i =0;i< n;i++){
		if(commands[i]==-2){
			init = (init -1 + 4)%4;
			continue;
		}
		if(commands[i]==-1){
			init = (init +1)%4;
			continue;
		}
		int count = commands[i];
		while(count>0){
			if(st.count({x + direc[init].first,y + direc[init].second})){
				break;
			}
			x+=direc[init].first;
			y+=direc[init].second;
			res= max(res, x*x + y*y);
			count--;
		}
	}
	return res;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
