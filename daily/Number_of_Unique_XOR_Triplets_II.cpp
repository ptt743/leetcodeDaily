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
        vector<bool> is_present(2048, false);
        vector<int> unique_nums;
        for (int num : nums) {
            if (!is_present[num]) {
                is_present[num] = true;
                unique_nums.push_back(num);
            }
        }
        
        // Bước 1: Tính XOR của 2 số
        vector<bool> has_2(2048, false);
        int n = unique_nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                has_2[unique_nums[i] ^ unique_nums[j]] = true;
            }
        }
        
        // Bước 2: Tính XOR cho số thứ 3 và đếm luôn kết quả
        vector<bool> has_3(2048, false);
        int count = 0;
        for(int val = 0; val < 2048; val++) {
            if(has_2[val]) {
                for(int num : unique_nums) {
                    if (!has_3[val ^ num]) {
                        has_3[val ^ num] = true;
                        count++;
                    }
                }
            }
        }
        
        return count;		
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
