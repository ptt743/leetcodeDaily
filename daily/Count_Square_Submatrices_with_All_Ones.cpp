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
	vector<vector<int>> matrix={{1,0,1},
		{1,1,0},
  {1,1,0}};

	 int n = matrix.size();
	 	int m = matrix[0].size();
			vector<int> curr ( m,0);
				int res = 0;
					for(int i =0;i< n;i++){
								for(int j = 0;j< m;j++){
												if(matrix[i][j]==1){
																	curr[j]++;
																				} else curr[j] = 0;
														}
										stack<int> st;
												for(int j = 0;j< m;j++){
																while(!st.empty() && curr[st.top()] >= curr[j]) st.pop();
																			int lastInd = (st.empty())?-1:st.top();
																			st.push(j);
																						int edge = min(curr[j], j - lastInd);
																									res += edge;
																											}
													}
						return res;
:w!
:q1

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
