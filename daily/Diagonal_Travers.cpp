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
	vector<vector<int>> mat;
	int m = mat.size();
	int n = mat[0].size();
	vector<int> res;
	for(int i =0;i< n;i++){
		int first =0, second = i;
		vector<int> temp;
		while(second>=0){
			temp.push_back(mat[first][second]);
			first++;
			second--;
			if(i%2==0){
				reverse(temp.begin(), temp.end());
			}
			for(int item : temp) res.push_back(item);
		}
	}
	for(int i = 1;i< m;i++){
		int first = i, second = n-1;
		vector<int> temp;
		while(first<m){
			temp.push_back(mat[first][second]);
			first++;
			second--;
		}
		if(n%2!=0 && i%2==0) reverse(temp.begin(), temp.end());
        	if(n%2==0 && i%2!=0) reverse(temp.begin(), temp.end());	
		for(int item : temp) res.push_back(item);
	}
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
