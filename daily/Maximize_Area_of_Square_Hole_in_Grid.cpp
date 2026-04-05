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
	int n,m;
	vector<int> hBars;
	vector<int> vBars;
	sort(hBars.begin(), hBars.end());
	sort(vBars.begin(), vBars.end());
	
	int pre = -1;
	int counth = 0;
    	int h = 0;
	for(int item:hBars){
		if(counth == 0) counth =1;
		if((item- pre) ==1) counth++;
		else {
			counth = 1;
		}
        	h = max(h,counth);
		pre = item;
	}
	pre = -1;
	int countv = 0;
    	int v = 0;
	for(int item:vBars){
		if(countv ==0) countv=1;
		if(item - pre==1) countv++;
		else {
			countv =1;
		}
        	v = max(v, countv);
		pre = item;
	}
	int len = min(h, v)+1;
	return len* len;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
