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
struct option{
	bool operator()(char a, char b){
		return a > b;
	}
};
void solve(){
	string s = "abc";
	priority_queue<char, vector<char>, option> pq;
	vector<vector<int>> indies (26, vector<int>());
	int n = s.size();
	for(int i =0;i< n;i++){
		if(s[i]!='*'){
			pq.push(s[i]);
			indies[s[i]-'a'].push_back(i);
		} else {
			int ind = pq.top() - 'a';
			s[indies[ind].back()] = '!';
			indies[ind].pop_back();
			pq.pop();
		}
	}
	string result = "";
	for(int i =0;i<s.size();i++){
		if(s[i]!='!' && s[i]!='*'){
		result += s[i];
		}
	}
	cout<< result<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
