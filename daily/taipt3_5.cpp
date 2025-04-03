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
	int n = nums.size();
        long long maxpre = nums[0];
	long long result = -1e12;
	long long maxProduct = -1e6;
        for(int i = 1;i<n-1;i++){
            long long product = maxpre - nums[i];
            maxProduct = max(product, maxProduct);
            maxpre = max(maxpre, (long long)nums[i]);
	    result = max(result, maxProduct* nums[i+1];
        }
        return (result<0)?0:result;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
