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
	string result;
	deque<char> dq;
	bool rever = false;
	for(char item : s){
		if(item =='*'){
            if(dq.empty()) continue;
			if(rever) dq.pop_front();
			else dq.pop_back();
		}
		else if(item=='%' )rever = !rever;
		else if(item=='#'){
            int sz = dq.size();
            for(int i = 0;i< sz;i++){
                dq.push_back(dq[i]);
            }
        }else {
		    if(rever) dq.push_front(item);
            else dq.push_back(item);
        }
	}
	if(!rever){
		while(!dq.empty()){
			result+=dq.front();
			dq.pop_front();
		}
	} else {
		while(!dq.empty()){
			result+= dq.back();
			dq.pop_back();
		}
	}
	return result;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
