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
	vecctor<vector<int>> mat;

	int n = mat.size();

	for(int i = 0;i< n;i++){
		int first = i, second = 0;
		vector<int> temp;
		while(first <n && second < n){
			temp.push_back(mat[first][second]);
			first++;
			second++;
		}
		sort(temp.begin(), temp.end());
		reverse(temp.begin(), temp.end());
		first = i, second = 0;
		int index=0;
		while(first < n && second < n){
			mat[first][second]= temp[index++];
			first++; second++;
		}
	}
	for(int i = 1;i< n;i++){
		int first = 0, second = i;
		vector<int> temp;
		while(first <n && second < n){
			temp.push_back(mat[first][second]);
			first++;
			second++;
		}
		sort(temp.begin(), temp.end());
		first = 0, second = i;
		int index=0;
		while(first < n && second < n){
			mat[first][second]= temp[index++];
			first++; second++;
		}
	}
	return mat;	
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
