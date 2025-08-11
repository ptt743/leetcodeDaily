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
	int n=2;
	vector<vector<int>> queries ={{0,0}};

	vector<int> power;
	string binary = "";
	while(n>0){
		char last = '0' + (n%2);
		binary += last;
		n/=2;
	}
	int mod = 1e9+7;
	for(int i =0; i < binary.size();i++){
		if(binary[i]=='1')
			power.push_back(i);
	}
	for(int i =1;i< power.size();i++){
		power[i]+=power[i-1];
	}
	function<int(int,int)> powerof2=[&](long long a, int b){
		long long result = 1ll;
		a%=mod;
		while(b>0){
			if(b&1){
				result = (result*a)%mod;
			}
			a = (a*a)%mod;
			b>>=1;
		}
		return result%mod;
	};
	vector<int> result;
	for(int i =0;i< queries.size();i++){
		int left = queries[i][0];
		int right = queries[i][1];
		int total = power[right] - ((left>0)?power[left-1]:0);
			
		result.push_back(powerof2(2,total));
	}
	for(int item : result) cout<< item <<endl;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
