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
	vector<string> wordsContainer;
	vector<string> wordsQuery;
	struct trie{
		vector<trie*> node;
		int index;
		trie(){
			index = -1;
			node = vector<trie*>(26, nullptr);
		}
	};
	trie* root = new trie();
	int minLen = INT_MAX;
	int minInd = 0;
	for(int i = 0;i< wordsContainer.size();i++){
		if(wordsContainer[i].size()< minLen){
			minLen = wordsContainer[i].size();
			minInd = i;
		}
	}

	function<void(string&, int)> insert=[&](string& s, int index){
		trie* temp = root;
		reverse(s.begin(), s.end());
		for(char item : s){
			if(temp->node[item-'a']== nullptr){
				temp->node[item-'a'] = new trie();
			}
			temp = temp->node[item-'a'];
			if(temp->index ==-1 || (temp->index!=-1 && wordsContainer[temp->index].size() > wordsContainer[index].size())){
				temp->index = index;
			}
		}
	};

	function<int(string&)> find = [&](string& s){
		trie* temp = root;
		reverse(s.begin(), s.end());
		int index =-1;
		for(char item : s){
			if(temp->node[item-'a']!=nullptr){
				temp = temp->node[item-'a'];
				index = temp->index;
			}else break;
		}
		if(index==-1) index = minInd;
		return index;
	};
	for(int i = 0 ;i< wordsContainer.size();i++){
		insert(wordsContainer[i],i);
	}
	vector<int> res(wordsQuery.size(),0);
	for(int i = 0; i< wordsQuery.size();i++){
		res[i] =  find(wordsQuery[i]);
	}
	return res;

}

void solve2(){
	vector<string> wordsContainer;
	vector<string> wordsQuery;
	        struct trie{
		vector<int> node;
		int index;
		trie(){
			index = -1;
			node = vector<int>(26, -1);
		}
	};
	vector<trie> tri;
	tri.emplace_back();
	int minLen = INT_MAX;
	int minInd = 0;
	for(int i = 0;i< wordsContainer.size();i++){
		if(wordsContainer[i].size()< minLen){
			minLen = wordsContainer[i].size();
			minInd = i;
		}
	}
	function<void(string&, int)> insert=[&](string& s, int index){
		reverse(s.begin(), s.end());
		int curr = 0;
		for(char item : s){
			if(tri[curr].node[item-'a']== -1){
				tri[curr].node[item-'a'] = tri.size();
                tri.emplace_back();
			}
			curr = tri[curr].node[item-'a'];
			if(tri[curr].index ==-1 || (tri[curr].index!=-1 && wordsContainer[tri[curr].index].size() > wordsContainer[index].size())){
				tri[curr].index = index;
			}
		}
	};
	function<int(string&)> find = [&](string& s){
		reverse(s.begin(), s.end());
		int index =-1;
		int curr = 0;
		for(char item : s){
			if(tri[curr].node[item-'a']!=-1){
				curr = tri[curr].node[item-'a'];
				index = tri[curr].index;
			}else break;
		}
		if(index==-1) index = minInd;
		return index;
	};
	for(int i = 0 ;i< wordsContainer.size();i++){
		insert(wordsContainer[i],i);
	}
	vector<int> res(wordsQuery.size(),0);
	for(int i = 0; i< wordsQuery.size();i++){
		res[i] =  find(wordsQuery[i]);
	}
	return res;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve2();
    return 0;
}
