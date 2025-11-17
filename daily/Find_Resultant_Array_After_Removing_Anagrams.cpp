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
	vector<string> words;
	int n = words.size();

	string left = sort(words[0].begin(), words[0].end());
	vector<string> res;
	res.push_back(words[0]);
	for(int i = 1;i< n;i++){
		string temp = sort(words[1].begin(), words[i].end());
		if(temp!=left){
			res.push_back(words[i]);
			left = temp;
		}
	}
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
