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
	int num;
	string temp = to_string(num);
	int n = temp.size();

	for(int i =0;i< n;i++){
		if(temp[i]=='6'){
			temp[i] = '9';
			break;
		}
	}
	int result = stoi(temp);
	return result;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
