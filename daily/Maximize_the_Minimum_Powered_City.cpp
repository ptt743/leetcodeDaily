#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<map>
#include<cmath>
#include<functional>
#include <algorithm>
#include <numeric>

#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
void solve(){
	vector<int> stations={4,4,4,4};
	int r = 0;
	int k = 3;
	int n = stations.size();
	vector<long long> count(n+2,0);
	for(int i =1;i<=n;i++){
		int left = max(1, i - r);
		int right = min(n+1, i + r+1);
		count[left]+= stations[i-1];
		count[right] -= stations[i-1];
	}

	long long left = ranges::min(stations);
        long long right = accumulate(stations.begin(), stations.end(), 0LL) + k;
	while(left<=right){
		long long mid = (left + right)/2;
		vector<long long> diff = count;
		long long remain = k;
		bool check = true;
		long long sum = 0ll;
		for(int i =1;i<=n;i++) {
			sum += diff[i];
			if(sum<mid){
				long long add  = mid - sum;
				if(remain< add){
					check = false;
					break;
				}
				remain -= add;
				int end = min(n+1, i + 2*r+1);
				diff[end]-=add;
				sum+=add;
			}
		}
		if(check) left= mid+1;
		else right = mid-1;
	}
	cout<< right<<endl;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
