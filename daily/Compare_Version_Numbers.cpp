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
	string version1;
	string version2;

	string temp ="";
	vector<int> nums1;
	for(int i =0;i< version1.size()+1;i++){
		if(i == version1.size() || version1[i]=='.'){
			nums1.push_back(stoi(temp));
			temp="";
			continue;
		}
		temp+=version1[i];
	}
	temp="";
	vector<int> nums2;
	for(int i =0;i< version2.size()+1;i++){
		if(i == version2.size() || version2[i]=='.'){
			nums2.push_back(stoi(temp));
			temp="";
			continue;
		}
		temp+=version2[i];
	}
	for(int i =0;i< max(nums1.size(), nums2.size());i++){
		int a = i < nums1.size()? nums1[i]:0;
		int b = i< nums2.size()?nums2[i]:0;
		if(a < b) return -1;
		if(a>b) return 1;
	}
	return 0;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
