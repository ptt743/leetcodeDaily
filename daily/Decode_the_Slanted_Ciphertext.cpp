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
	string encodedText;
	int rows;
	int n = encodedText.size();
	vector<string> arr(rows,"");
	int len = n/rows;
	int count = 0;
	for(int i =0;i< n; i+=len){
		string temp = encodedText.substr(i,len);
		arr[count++] = temp;
	}
	string res = "";
	for(int i =0;i< len;i++){
		int x = 0;
		int y =i;
		while(x < rows && y < len){
			res +=arr[x][y];
			x++;
			y++;
		}
	}
	int last = res.size()-1;
	while(last>=0){
		if(res[last]!=' ') break;
		last--;
	}
	res= res.substr(0, last+1);
	return res;
	
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
