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
	vector<vector<int>> matrix;
	int n = matrix.size();
	int count =0;
	int maxVal = INT_MAX;
	long long sum = 0;
    	bool check = false;
	for(int i =0;i< n;i++){
		for(int j =0;j< n;j++){
            if(matrix[i][j]==0) check = true;
			if(matrix[i][j]<0){ 
				sum+= matrix[i][j]*(-1);
                count++;
			}else {
				sum+= matrix[i][j];
			}
            maxVal = min(maxVal, abs(matrix[i][j]));
		}
	}
	if(!check && count%2!=0) sum+= (-1)*maxVal*2;
	return sum;	
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
