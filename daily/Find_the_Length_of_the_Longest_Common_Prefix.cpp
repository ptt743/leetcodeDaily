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
	vector<int> arr1;
	int na = arr1.size();
	unordered_set<int> sta;
	for(int i =0; i<na;i++){
		while(arr1[i]>0){
			sta.insert(arr1[i]);
			arr1[i]/=10;
		}
	}
	int maxVal = 0;
	int nb = arr2.size();
	for(int i =0;i< nb;i++){
		while(arr2[i]>0){
			if(sta.find(arr2[i])!=sta.end()){
				maxVal = max(arr2[i]);
			}
		}	
		arr2[i]/=10;
	}
	if(maxVal ==0) return 0;

	return to_string(maxVal).size();
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
