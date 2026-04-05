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
	string a;
	string b;
	if(a.size() < b.size()) swap(a,b);
	int n1 = a.size()-1;
	int n2= b.size()-1;
	int remain = 0;
	string res = "";
	while(n1>=0 && n2>=0){
		int temp = (a[n1]-'0') + (b[n2]-'0') + remain;
		remain = 0;
        cout<< temp<<endl;
		if(temp ==3){
			res+= '1';
			remain = 1;
		} else if( temp ==2){
			res+= '0';
			remain = 1;
		} else if( temp==1){
			res+= '1';
		} else {
			res+= '0';
		}
		n1--;
		n2--;
	}
		while(n1>=0){
			int temp = (a[n1]-'0') + remain;
			remain = 0;
			if(temp==2){
				res+='0';
				remain = 1;
			}else if(temp == 1){
				res+='1';
			} else {	
                res+='0';
			}
            n1--;
		}
		if(remain) res+='1';
	reverse(res.begin(), res.end());
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
