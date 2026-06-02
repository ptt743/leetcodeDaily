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
	vector<int> nums;
	int n = nums.size();

	sort(nums.begin(), nums.end());
        int n = nums.size() -1;
        if(n<1) return false;
        
        for(int i =1;i<=n-1;i++){
            if(i != nums[i-1]) return false;
        }
        if(nums[n-1]!=n) return false;
        if(nums[n]!=n) return false;
        return true;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
