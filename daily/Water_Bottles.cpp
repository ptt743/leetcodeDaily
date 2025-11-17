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
	int numB=15;
	int numE=4;
	int count = 0;
	int temp =0;
	while(1){
		count+= numB;
		temp+=  numB;
		numB = temp/numE;
		if(numB==0) break;
		temp = temp%numE;
	}
	cout<< count <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
