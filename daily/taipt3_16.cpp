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
	vector<int> arr;
	int a  = 0 , b = 0, c = 0;
	int n = arr.size();
	int count = 0;
	for(int i =0;i< n-2;i++)
		for(int j = i+1;j<n-1;j++){
			for(int k = j+1;k<n;k++){
				if(abs(arr[i] - arr[j])<=a
				   && abs(arr[j] - arr[k])<=b
				   && abs(arr[i] - arr[k]) <=c)
					count++;
			}
		}
	cout<< count<< endl;
}

void solve2(){
	vector<int> sum(1001, 0);
	int result = 0;
    	int n = arr.size();
	for(int j = 0;j<n-1;j++){
		for(int k = j+1;k<n;k++){
			if( abs( arr[k] - arr[j]) <=b){
				int lj = arr[j] - a, rj = arr[j] + a;
				int lk = arr[k] - c, rk = arr[k] + c;
				int l = max(0,max( lj, lk));
				int r = min(1000,min( rj,rk));
				if( l<=r){
					if(l==0) result += sum[r];
					else result += sum[r] - sum[l-1];
				}

			}
		}
		for(int k = arr[j];k<1001;k++) sum[k]++;
	}
	cout<< result <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
