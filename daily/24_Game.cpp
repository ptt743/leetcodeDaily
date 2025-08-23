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
	vector<int> cards;
	function<bool(vector<double>&)> dfs = [&]( vector<double>& arr){

		if(arr.size()==1)
			return fabs(arr[0]-24.0)< 1e-6;
		int n = arr.size();
		for(int i =0;i< n;i++){
			for(int j = 0;j< n;j++){
				if(i==j) continue;

				vector<double> next;
				for(int k = 0;k< n;k++)
					if(k!=i && k!=j)
						next.push_back(arr[k]);
				double a = arr[i], b = arr[j];
				vector<double> res = {a-b, a+b, a*b};
				if(fabs(a)> 1e-6) res.push_back(b/a);
				if(fabs(b)> 1e-6) res.push_back(a/b);

				for(double item : res){
					next.push_back(item);
					if(dfs(next)) return true;
					next.pop_back();
				}
			}
		}
		return false;
	};
	vector<double> arr(cards.begin(), cards.end());
	return dfs(arr);
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
