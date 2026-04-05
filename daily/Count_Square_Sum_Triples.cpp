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
	int count=0;
	for(int a = 1;a<=n-1;a++){
		for(int b = 1;b<=n-1;b++){
			for(int c = b+1; c<=n;c++){
				if( c*c == b*b + a*a) count++;		
			}
		}
	}
	return count;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
