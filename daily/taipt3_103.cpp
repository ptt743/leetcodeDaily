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
	int eventTime = 21;
	int k = 1;
	vector<int> startTime ={7,10,16};
	vector<int> endTime = {10,14,18};

	int n = startTime.size();

	vector<int> dur;
	int ending = 0;
	for(int i =0;i<n;i++){
		dur.push_back(startTime[i] - ending);
		ending = endTime[i];
	}
	if(eventTime - ending >0) dur.push_back(eventTime - ending);

	for(int i =1;i< dur.size();i++) dur[i]+=dur[i-1];

	int dis = k+1;
	int result = 0;
	for(int i =0;i< dur.size();i++){
		if(i- dis>=0){
			result = max(result, dur[i] - dur[i - dis]);
			continue;
		}
		result = max(result, dur[i]);
	}
	cout<< result <<endl;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
