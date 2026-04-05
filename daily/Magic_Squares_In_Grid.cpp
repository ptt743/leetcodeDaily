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
	vector<vector<int>> grid;
	int n = grid.size();
	int m = grid[0].size();
	int count = 0;
	for(int i = 0;i< n;i++){
		for(int j = 0;j< m;j++){
			if(i+2<n && j+2<m){
				unordered_set<int> st;
				unordered_set<int> stt;
				int sum_diagonals = 0;
				for(int count1 = 0;count1<3;count1++){
					int sum = 0;
					for(int count2 = 0; count2<3;count2++){
						int val = grid[i+ count1][j+count2];
						sum+=val;
						if(count1 == count2) sum_diagonals += val;
						if(val<=9){
							st.insert(val);
						}
					}
					stt.insert(sum);
				}
				stt.insert(sum_diagonals);
				for(int count2 = 0;count2<3;count2++){
					int sum = 0;
					for(int count1 = 0; count1<3;count1++){
						int val = grid[i+ count1][j+count2];
						sum+=val;
						if(val<=9){
							st.insert(val);
						}
					}
					stt.insert(sum);
				}

				int sum_disgonals1 = 0;
				int count1 =2, count2 = 0;
				while(count1>=0){
					int val = grid[i+ count1][j+count2];
					sum_disgonals1+= val;
					count1--;
					count2++;
				}
				stt.insert(sum_disgonals1);
				
				if(stt.size()==1 && st.size()==9) count++;
			}
		}
	}
	return count;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
