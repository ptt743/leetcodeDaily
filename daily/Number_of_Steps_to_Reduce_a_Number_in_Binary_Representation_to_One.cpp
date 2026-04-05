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
	string s;
	int n = s.size();
	int count = 0;
	int right = n-1;
	for(int i = 0;i< n;i++){
		if(s[i]=='1') count++;
	}
	bool check = ( count==1) && ( s[right]=='1');
	int res=0;
	while(!check){
		res++;
		if(s[right]=='0'){
			right--;
		} else {
			int remain = 1;
			for(int i = right;i>=0;i--){
				int temp = (s[i]-'0') + remain;
				if(temp ==2) {
					s[i]='0';
					remain = 1;
				}else if(temp==1) {
					s[i]='1';
					remain = 0;
				} else {
					remain = 0;
				}
			}
			if(remain ==1) {
				res+= right+1;
				return res;
			}
		}
		int count1 = 0;
		for(int i = right;i>=0;i--){
			if(s[i]=='1')count1++;
		}
		check = (count1==1) && (s[right]=='1');
	}
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
