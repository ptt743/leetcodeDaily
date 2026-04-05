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
	string bottom;
	vector<string> allows;
	vector<vector<int>> T(7, vector<int>(7,0));
	unordered_set<string> memo;

	for(string item : allows){
		T[item[0]-'A'][item[1]-'A'] |= (1<<(item[2]-'A'));
	}
	int n = bottom.size();
	function<bool(string, string)> dfs =[&]( string curr, string next){
		if(curr.size()==1) return true;
		if(next.size() == curr.size()-1){
			if(memo.find(next)!=memo.end()) return false;
			return dfs(next,"");
		}
		int i = next.size();
		int u = curr[i] -'A';
		int v = curr[i+1]-'A';
		for (int i = 0;i<7;i++) {
			if(T[u][v] & (1<<i)){
                        char c = 'A' + i;
            			if (dfs(curr, next + c)) return true;
			}
		}

        if (next == "") memo.insert(curr);
        return false;
		
	};
	return dfs(bottom,"");

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
