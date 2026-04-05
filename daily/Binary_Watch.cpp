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
	int turnOn;
	vector<string> res;
	for(int i = 0;i < 1<<(10);i++){
		int count = 0;
		for(int j = 0;j<10;j++){
			if(i & ( 1<< j)){
				count++;
			}
		}
		if(count!= turnOn) continue;
        cout<< count<<endl;

		int minute =0;
		for(int j = 0;j< 6;j++){
			if(i & (1<<j)){
				minute += ( 1<< j);
			}
		}
		int time = 0;
		for(int j =0 ;j< 4;j++){
			if(i & (1<<(j+6))){
				time += (1 << j);
			}
		}
		if(time >=12 || minute >=60) continue;

		string strtime = to_string(time);
		string strminute = to_string(minute);
		if(minute<10) strminute = "0" + strminute;
		string display = strtime +":"+ strminute;
        res.push_back(display);
	}
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
