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
	struct Trie{
		vector<Trie*> arr;
		bool end;
		Trie(){
			arr = vector<Trie*>(2, nullptr);
			end = false;
		}
	};
	Trie* root = new Trie();
	function<void(int)> insert=[&](int val){
		Trie *temp = root;
		vector<int> res = vector<int>(32,0);
		int index = 31;
		while(val!=0){
			int remain = val%2;
			val = val/2;
			res[index--] = remain;
		}
		for(int i = 0;i< 32;i++){
			if(temp->arr[res[i]]==nullptr){
				temp->arr[res[i]] = new Trie();
			}
			temp = temp->arr[res[i]];
		}
		temp->end = true;
	};

	function<int(int)> find= [&](int val){
		vector<int> res = vector<int>(32,0);
        int value = val;
		int index = 31;
		while(val!=0){
			int remain = val%2;
			val = val/2;
			res[index--] = remain;
		}
		Trie* temp = root;
		int result =0;
		for(int i = 0;i< 32;i++){
			int rever = 1 - res[i];
			if(temp->arr[rever]!=nullptr){
				temp = temp->arr[rever];
				result+=1<<(31-i);
			}else {
				temp = temp->arr[res[i]];
			}
		}
		return result;
	};
	int ans = 0;
	for(int i = 0;i< n;i++){
		if(i>0)ans = max(ans, find(nums[i]));
		insert(nums[i]);
	}
	return ans;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
