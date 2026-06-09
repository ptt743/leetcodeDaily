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
	int mass;
	vector<int>& a;
	sort(asteroids.begin(), asteroids.end());
        long long sum = mass;
        for(int item : asteroids){
            if(item> sum) return false;
            sum +=item;
        }
        return true;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
