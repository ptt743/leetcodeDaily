#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<cmath>
#include<functional>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
void solve(){
	vector<vector<int>> matrix={{-5}};
	int k= 1;
	int n = matrix.size();
	int count = 0;
	vector<int> indexs(n,0);
	int ans =0;
	while(count<k){
		int temp = 1e9;
		int index = 0;
		for(int i =0;i< n;i++){
			if(indexs[i] <n && matrix[i][indexs[i]] < temp){
				temp = matrix[i][indexs[i]];
				index = i;
			}
		}
		count++;
		indexs[index]++;
		ans = temp;
	}
	cout<< ans<<endl;

}
void solve2(){
	vector<vector<int>> matrix={{1,5,9},{10,11,13},{12,13,15}};
	int k= 8;
	int n = matrix.size();
	int m = matrix[0].size();
	priority_queue<int> pq;
	for(int i =0;i< n;i++){
		for(int j = 0;j< m;j++){
			pq.push(matrix[i][j]);
			if(pq.size()>k) pq.pop();
		}
	}
	cout<< pq.top()<<endl;
}

void solve3(){
	vector<vector<int>> matrix={{1,5,9},{10,11,13},{12,13,15}};
	int k= 8;
	int n = matrix.size();
	int m = matrix[0].size();

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve2();
    return 0;
}
