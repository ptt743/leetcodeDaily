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
	int side;
	vector<vector<int>>& points;
	int k;
	vector<long long> arr;
	for(auto& p: points){
        int x = p[0], y = p[1];
		if(x==0) arr.push_back(4ll*side - y);
		if(y==0) arr.push_back(1ll*x);
		if(x==side) arr.push_back(1ll*side + y);
		if(y==side) arr.push_back(3ll*side -x);
	}
	sort(arr.begin(), arr.end());
	auto check = [&](long long limit) -> bool {
            for (long long start : arr) {
                long long end = start + side * 4LL - limit;
                long long cur = start;
                for (int i = 0; i < k - 1; i++) {
                    auto it = ranges::lower_bound(arr, cur + limit);
                    if (it == arr.end() || *it > end) {
                        cur = -1;
                        break;
                    }
                    cur = *it;
                }
                if (cur >= 0) {
                    return true;
                }
            }
            return false;
        };

	int left = 1, right = side;
	while( left<=right){
		int mid = ( left + right)/2;
		if(check(mid)) left = mid+1;
		else right = mid-1;

	}
	return right;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
