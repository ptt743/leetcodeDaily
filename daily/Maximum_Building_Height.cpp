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
	restrictions.push_back({1, 0});
        
        sort(restrictions.begin(), restrictions.end());
        
        if (restrictions.back()[0] != n) {
            restrictions.push_back({n, n - 1});
        }
        
        int m = restrictions.size();
        
        for (int i = 1; i < m; ++i) {
            int id_prev = restrictions[i - 1][0];
            int h_prev = restrictions[i - 1][1];
            int id_curr = restrictions[i][0];
            int h_curr = restrictions[i][1];
            
            restrictions[i][1] = min(h_curr, h_prev + (id_curr - id_prev));
        }
        
        for (int i = m - 2; i >= 0; --i) {
            int id_next = restrictions[i + 1][0];
            int h_next = restrictions[i + 1][1];
            int id_curr = restrictions[i][0];
            int h_curr = restrictions[i][1];
            
            restrictions[i][1] = min(h_curr, h_next + (id_next - id_curr));
        }
        
        int max_ans = 0;
        for (int i = 1; i < m; ++i) {
            int id1 = restrictions[i - 1][0];
            int h1 = restrictions[i - 1][1];
            int id2 = restrictions[i][0];
            int h2 = restrictions[i][1];
            
            int current_max = (id2 - id1 + h1 + h2) / 2;
            max_ans = max(max_ans, current_max);
        }
        
        return max_ans;	
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
