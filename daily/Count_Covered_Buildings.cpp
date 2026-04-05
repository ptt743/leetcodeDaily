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
	vector<vector<int>> builds;
	vector<pair<int,int>> arr;
	multiset<int> mtyr;
	multiset<int> mtyl;
	vector<int> xs;
	int sz = builds.size();
	function<bool(vector<int>&, vector<int>&)> option=[&](vector<int>& a, vector<int>&b){
		return a[0] < b[0] || (a[0]== b[0] && a[1]< b[1]);
	};
	sort(builds.begin(), builds.end(), option);

	for(int i = 0;i<sz;i++){
		xs.push_back(builds[i][0]);
		mtyr.insert(builds[i][1]);
	}
	int count = 0;
	for(int i = 0;i< sz;i++){
		cout<< builds[i][0] <<" "<<builds[i][1]<<endl;
		auto it = mtyr.find(builds[i][1]);
		mtyr.erase(it);
		int indexl = lower_bound(xs.begin(), xs.end(), builds[i][0])- xs.begin();
		int indexr = upper_bound(xs.begin(), xs.end(), builds[i][0]) - xs.begin();
		if( i > indexl && i < indexr-1 && mtyl.find(builds[i][1])!=mtyl.end() && mtyr.find(builds[i][1])!=mtyr.end()){
			count++;
		}
		mtyl.insert(builds[i][1]);
	}
	return count;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
