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
	vector<int>& positions;
	vector<int>& healths;
	string directions;
	struct node{
        	int ind;
		int pos;
		int health;
		char direc;
	};
	int n = positions.size();
	vector<node> arr;
	for(int i = 0;i< n;i++){
		arr.push_back({i, positions[i], healths[i], directions[i]}); 
	}
	sort(arr.begin(), arr.end(), [](node a, node b) { return a.pos < b.pos;});
	deque<node> dq;
	for(int i =0;i< n;i++){
		node temp = {arr[i].ind, arr[i].pos, arr[i].health, arr[i].direc};
		bool check = false;
		while(!dq.empty() && dq.back().direc != temp.direc && dq.back().direc =='R'){
			node back = dq.back();
			dq.pop_back();
		    if(back.health > temp.health){
				temp = {back.ind, back.pos, back.health - 1, back.direc};
		    }else if (back.health < temp.health){
			temp = {temp.ind, temp.pos, temp.health - 1, temp.direc};
		    }else {
			check = true;
			break;
		    }
		}
		if(check) continue;
		dq.push_back({temp.ind, temp.pos, temp.health, temp.direc});
	}
	vector<pair<int, int>> res;
	while(!dq.empty()){
		node top = dq.front();
		dq.pop_front();
		res.push_back({top.ind, top.health});
	}
    	sort(res.begin(), res.end());
    	vector<int> ret;
    	for(pair<int,int> item : res){
        	ret.push_back(item.second);
    	}
	return ret;	

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
