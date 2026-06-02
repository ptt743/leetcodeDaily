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
	vector<string>& products;
	string searchWord;
	struct trie{
		vector<trie*> child;
		set<string> st;
        trie() : child(26, nullptr) {}
	 };
	 trie* root = new trie();
	 function<void(string&)> insert = [&]( string& s){
		int n = s.size();
		trie* temp = root;
		for(int i = 0;i< n;i++){
			if(temp->child[s[i]-'a']==nullptr){
				temp->child[s[i]-'a'] = new trie();
			}
			temp = temp->child[s[i]-'a'];
			temp->st.insert(s);
			if(temp->st.size()>3) temp->st.erase(--temp->st.end());
		}
	 };
	 for(string item: products) insert(item);
	 trie* temp = root;
	 vector<vector<string>> res;
	 for(char item : searchWord){
		vector<string> curr;
		if(temp!=nullptr && temp->child[item-'a']!=nullptr){
			temp = temp->child[item - 'a'];
			for(string word: temp->st){
				curr.push_back(word);
			}
			res.push_back(curr);
		} else {
            res.push_back(curr);
            temp=nullptr;
            continue;
        };
	 }
	 return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
