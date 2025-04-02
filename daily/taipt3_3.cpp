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
	vector<vector<int>> questions={{1,1},{2,2},{3,3},{4,4},{5,5}};
	int n = questions.size();
	long long result  = 0;
	for(int i = n -1; i>=0;i--){
		long long value  = questions[i][0];
		int brainpower = questions[i][1];
		int preIndex = i + brainpower +1;
		if(preIndex<n) value = max(value,questions[i][0] + (long long)questions[preIndex][0]);
		if(i+1<n) value = max( value, (long long)questions[i+1][0]);
		questions[i][0] = value;
		result = max(result, value);
	}
	cout<< result <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
