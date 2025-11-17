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
	vector<int> nums={1,1,2,2,3,4,2,3};
	int x = 2;
	int k = 6;

	int n = nums.size();
	vector<int> count(51,0);
	set<pair<int,int>> st;
	int left = 0;
	vector<int> res;
	
	for(int i = 0;i< n;i++){
		count[nums[i]]++;
		if(i>=k-1){
			vector<pair<int,int>> temp;
			
			for(int i = 1;i<=50;i++){
				temp.push_back({count[i], i});
			}
			sort(temp.begin(), temp.end(), [](pair<int,int> a, pair<int,int> b){return a.first < b.first || (a.first == b.first && a.second< b.second);});
			int index = temp.size()-1;
			int result = 0;
			int cou = 0;
			while(index>=0 && cou<x){
				result += temp[index].first* temp[index].second;
				cou++;
				index--;
			}
			res.push_back(result);
			count[nums[left]]--;
			left++;
		}

	}
	for(int item: res) cout<< item<<" ";
		
	


}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
