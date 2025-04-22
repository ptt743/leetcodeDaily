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
        int count = 0;
        for(int i =0;i< n-1;i++){
            for(int j = i+1;j<n;j++){
                if(nums[i]== nums[j] && i*j%k==0){
                    count++;
                }

            }

        }
        cout<< count;		
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
