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
#include <cstdlib>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
vector<int> prefix;
vector<vector<int>> points;
void solve(vector<vector<int>>& rects) {
        points = rects;
        int n  = rects.size();
        int total = 0;
        for( int i =0;i< n;i++){
            int x1 = rects[i][0], y1 = rects[i][1];
            int x2 = rects[i][2], y2 = rects[i][3];
            total += (x2-x1+1)*(y2-y1+1);
            prefix.push_back(total);
        }
}
    
vector<int> pick() {
        int rand_index = rand()%(prefix.back()) + 1;
        int index = lower_bound(prefix.begin(), prefix.end(), rand_index) - prefix.begin();
        int x1 = points[index][0], y1 = points[index][1];
        int x2 = points[index][2], y2 = points[index][3];

        int x = x1 + rand()%(x2-x1+1);
        int y = y1 + rand()%(y2-y1+1);
        return {x,y};
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
