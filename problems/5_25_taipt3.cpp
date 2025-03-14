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
vector<int> w;
vector<int> prefix;
void solve(){
	w = w;	
	int n = w.size();
	prefix = vector<int>(n,0);
	prefix[0] = w[0];
	for(int i =1;i< n;i++) prefix[i] = prefix[i-1] + w[i];
}

int pickIndex(){
	int randomIndex = random()%prefix.back() + 1;
	int index = lower_bound( prefix.begin(), prefix.end(), randomIndex) - prefix.begin();
	return index;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
