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
	vector<string> wordDict;

	int n = s.size();
	int m = wordDict.size();
	struct node{
		vector<int> count= vector<int>(26,0);
		bool end = false;
	};
	vector<node> trie(1);
	function<void(string&)> insert=[&](string& input){
		int u = 0;
		for(int i = 0;i< input.size();i++){
			int index = input[i] - 'a';
			if(trie[u].count[index]==0){
				trie[u].count[index] = trie.size();
				trie.push_back(node());
			}
			u = trie[u].count[index];
		}
		trie[u].end = true;
	};
	
	for(int i = 0;i< wordDict.size();i++){
		insert(wordDict[i]);
	}
	int mm[301][10000];
    	for(int i = 0;i<301;i++){
        for(int j = 0;j<10000;j++)
            mm[i][j] = -1;
    	}
	function<bool(int,int)> dfs =[&](int index, int u){
		if(mm[index][u]!=-1) return (bool)mm[index][u];
		if(index==n && trie[u].end) return true;
		if(index==n && !trie[u].end) return false;
        	int idx = s[index] -'a';
		bool res = false;
		if(trie[u].end){
             		res|=dfs(index, 0);
        	}
       		if(trie[u].count[idx]==0) res|=false;
		else res|=dfs(index+1,trie[u].count[idx]);
		mm[index][u] = res;
        	return res;
	};
	return dfs(0,0);	
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
