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
	int poured;
	int query_row;
	int query_glass;
	queue<pair<pair<int,int>, double>> qq;
	qq.push({{0,0},poured});
	map<pair<int,int>, double> res;
	while(!qq.empty()){
		int n = qq.size();
		map<pair<int, int>, double> mp;
		for(int i =0;i< n;i++){
			pair<pair<int,int>, double> fr = qq.front();
			qq.pop();
			//mp[{fr.first.first, fr.first.second}]+=fr.second;
            double reserse = fr.second;
			int a = fr.first.first;
			int b = fr.first.second;
			if(reserse > 1){
				reserse -=1.0;
				res[{a, b}] = 1;
                if(a+1>=100 || b+1>=100 ) continue;
				mp[{a+1, b}]+= reserse/2.0;
				mp[{a+1, b+1}]+=reserse/2.0;
			}else {
				res[{a,b}] = reserse;
			}
		}
		for(auto item : mp){
			qq.push({{item.first.first, item.first.second}, item.second});
		}
	}
	if(res.find({query_row, query_glass})==res.end()) return 0;
	return res[{query_row, query_glass}];
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
