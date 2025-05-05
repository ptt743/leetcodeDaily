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
    int n = tops.size();
    vector<int> candidates = {tops[0], bottoms[0]};
    int res = INT_MAX;

    for (int val : candidates) {
        // Case: make all tops == val
        bool canDo = true;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (tops[i] == val) continue;
            else if (bottoms[i] == val) count++;
            else {
                canDo = false;
                break;
            }
        }
        if (canDo) res = min(res, count);

        // Case: make all bottoms == val
        canDo = true;
        count = 0;
        for (int i = 0; i < n; ++i) {
            if (bottoms[i] == val) continue;
            else if (tops[i] == val) count++;
            else {
                canDo = false;
                break;
            }
        }
        if (canDo) res = min(res, count);
    }
    return res == INT_MAX ? -1 : res;
    
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
