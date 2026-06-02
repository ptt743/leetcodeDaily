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
	vector<string>& queries;
	vector<string>& dictionary;
	int n  = queries.size();
        int m = dictionary.size();
	int len = queries[0].size();
	vector<string> res;
	for(int i =0;i< n;i++){
        bool check = false;
		for(int j= 0;j<m;j++){
			int count = 0;
			for(int k =0;k<len;k++){
				if(queries[i][k]!= dictionary[j][k]) count++;
			}
			if(count<=2) {check = true; break;}
		}
        if(check)res.push_back(queries[i]);
	}
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
