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
	vector<int> A;
	vector<int> B;

	unordered_set<int> sta, stb;
	int count =0;
	vector<int> c(n,0);
	for(int i = 0; i< n;i++){
		if(sta.find(A[i])==sta.end()){
			sta.insert(A[i]);
			if(stb.find(A[i])!=stb.end()) count++;
		}
		if(stb.find(B[i])==stb.end()){
			stb.insert(B[i]);
			if(sta.find(B[i])!=sta.end()) count++;
		}
		c[i] = count;
	}
	return count;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
