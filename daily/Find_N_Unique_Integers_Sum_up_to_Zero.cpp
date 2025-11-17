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
	int n;
	vector<int> result(n,0);
	int m = n;
	int begin = 0;
	if(m%2!=0){
		result[0] = 0;
		begin = 1;
	}
	int initValue = 1;
	for(int i =begin;i<m;){
		result[i] = initValue;
		result[i+1] = (-1)* initValue;
        	i+=2;
        	initValue++;
	}
	return result;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
