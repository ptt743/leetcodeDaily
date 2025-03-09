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
bool option(pair<int,char> a, pair<int, char>b){
	return a.first > b.first;
}
void solve(){
	string s;
	cin>> s;
	int n = s.size();
	vector<int> count(256,0);
	for(int i =0;i<n;i++){
		count[s[i]-'0']++;
	}
	vector<pair<int,char>> arr;
	for(int i =0;i<256;i++){
		if(count[i]>0){
			arr.push_back({count[i], '0'+i});
		}
	}
	sort(arr.begin(), arr.end(),option);
	int left =0;
	string result = "";
	for(int i =0;i< arr.size();i++){
		int sz = arr[i].first;
		for(int j =0;j<sz;j++){
			result+=arr[i].second;
		}
	}
	cout<< result <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
