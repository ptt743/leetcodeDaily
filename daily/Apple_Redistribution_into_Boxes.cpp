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
	vector<int> apple;
	vector<int> boxs;
	int n = apple.size();
	int m = boxs.size();

	sort(boxs.begin(), boxs.end());
	int sum = 0;
	for(int i = 0;i< n;i++){
		sum += apple[i];
	}
	int count =0;
				
	for(int j = m-1;j>=0;j--){
		if(sum>0){
			sum-= min(sum, boxs[j]);
			count++;
		} else break;
	}
	return count;
}

 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
