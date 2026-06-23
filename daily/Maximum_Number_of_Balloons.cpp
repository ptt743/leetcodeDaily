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
	string text;
	int n = text.size();
	vector<int> count(26,0);
	for(char  item : text){
		count[item - 'a']++;
	}
	string pattern = "balloon";
	int minVal = INT_MAX;
    for(char item : pattern){
        if(item =='o' || item =='l') minVal = min( minVal, count[item-'a']/2);
        else minVal = min(minVal, count[item-'a']);
	}
	return minVal;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
