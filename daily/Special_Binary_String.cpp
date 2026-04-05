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
	int count = 0, i = 0;
    	vector<string> res;
    	for (int j = 0; j < s.size(); ++j) {
        	if (s[j] == '1') count++;
        	else count--;
        
        	if (count == 0) {
            		res.push_back("1" + makeLargestSpecial(s.substr(i + 1, j - i - 1)) + "0");
            		i = j + 1;
        	}
    	}
    	sort(res.begin(), res.end(), greater<string>());
    	string ans = "";
    	for (auto& str : res) ans += str;
    	return ans;		
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
