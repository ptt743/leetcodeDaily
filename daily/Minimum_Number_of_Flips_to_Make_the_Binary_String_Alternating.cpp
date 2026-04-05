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
	int n = s.size();

	vector<pair<int,int>> count(2);

	for(int i =0;i< n;i++){
        int t = s[i]-'0';
        if(t) count[i%2].second++;
        else count[i%2].first++;
	}
	vector<pair<int,int>> prefix(2);
	int res = INT_MAX;
	for(int i = 0;i<n;i++){
		int len = n- i;
		vector<pair<int,int>> temp (2);
		temp[0] = {count[0].first - prefix[0].first, count[0].second - prefix[0].second};
		temp[1] = {count[1].first - prefix[1].first, count[1].second - prefix[1].second};

		if(i%2!=0) swap(temp[0], temp[1]);
		//1
		res = min(res, temp[0].first + temp[1].second + ((len%2==0)?(prefix[0].first + prefix[1].second):(prefix[0].second + prefix[1].first)));
		//0
		res = min(res, temp[0].second + temp[1].first + ((len%2==0)?(prefix[0].second + prefix[1].first):(prefix[0].first + prefix[1].second)));
        int t = s[i]-'0';
        if(t) prefix[i%2].second++;
        else prefix[i%2].first++;
	}
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
