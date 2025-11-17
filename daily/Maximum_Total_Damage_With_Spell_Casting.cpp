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
	vector<int> power;
	int n = power.size();

	set<int> st;
	for(int i =0;i< n;i++) st.insert(power[i]);

	long long result = 0;
	while(!st.empty()){
		long long product = 1;
		auto it = st.rbegin();
		product*=(*it);
		while(it!=null){
			it = st.upper_bound(*(it)-3);
			if(it!=st.begin()){
			it--;
			product*=(*it);
			}else {
				it = null;
			}
		}
		result = max(result, product);
	}
	cout<< result <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
