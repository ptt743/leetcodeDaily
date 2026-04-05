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
	vector<string> arr;
        int n = arr.size();
	int len = arr[0].size();
	vector<bool> visited(len,false);
	
	vector<vector<bool>> che(len,vector<bool>(n,false));

	for(int i = 1;i< n;i++){
		for(int j = 0;j< len;j++){
			if(arr[i][j]> arr[i-1][j]) che[j][i] = true;
		}
	}
	int left = -1;
	for(int j = 0;j<len;j++){
		bool check = true;
		bool check2 = true;
		for(int i = 1; i< n;i++){
			if(arr[i][j] < arr[i-1][j]){
				if(left >-1 && che[left][i] ){
					continue;
				} else {
					check = false;
				}
			}
		}
		if(check){
			if(left>-1){
                for(int i  =1;i<n; i++){
			    	che[j][i] = che[j][i] ||  che[left][i];
                }
            }
			left = j;
		}
		if(!check) visited[j] = true;
	}
	int res = 0;
	for(int i = 0;i< len; i++)
		if(visited[i]) res++;
	return res; 
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
