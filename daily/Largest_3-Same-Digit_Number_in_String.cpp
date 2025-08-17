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
	string num;
	int n = num.size();

	map<char,int> mp;
	int left = -1;
	int maxVal = -1;
	for(int  i=0;i<n;i++){
		mp[num[i]]++;
		if( i - left >=3 || i ==n-1 || left =0){
			if(i-left>=3){
				mp[num[left]]--;
				if(mp[num[left]]==0) mp.remove(num[left]);
				left++;
			}
			if(mp.size()==1 && mp[num[i]]==3) maxVal = max(maxVal, num[i] - '0');
		}
	}
	if(maxVal ==-1) return "";
	else{
		string result = string(3, '0' + maxVal);
		return result;
	}

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
