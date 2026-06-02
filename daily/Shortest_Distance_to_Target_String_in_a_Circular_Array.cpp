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
	vector<string>& words;
	string target;
	int startIndex;
	vector<int> indexs;
	int count = 0;
	for(string item : words){
		if(item== target){
			indexs.push_back(count);
		}
		count++;
	}
    	if (indexs.empty()) {
            return -1;
        }
	int n = words.size();
	auto index = upper_bound(indexs.begin(),  indexs.end(), startIndex);

	int left = (index == indexs.begin())?(n - *(indexs.end()-1) + startIndex):(startIndex - *(index-1));

	int right = (index== indexs.end())?( *indexs.begin() + n - startIndex):(*index - startIndex);
	
	return min(left, right);
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
