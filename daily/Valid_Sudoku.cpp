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
	vector<vector<char>> board;

	int n = board.size();

	for(int i =0;i<9;i++){
		set<int> col;
		set<int> row;
		bool check = true;
		for(int j = 0;j<9;j++){
			if(board[i][j]!='.' &&  col.find(board[i][j])!=col.end()) {
				check = false;
				break;
			}
			if(board[i][j]!='.')col.insert(board[i][j]);

			if( board[j][i]!='.' && row.find(board[j][i])!= row.end()){
				check = false;
				break;
			}
			if(board[j][i]!='.')row.insert(board[j][i]);
		}
		if(!check) return false;
	}
	for(int i =0;i<9;i+=3){
		for(int j = 0; j<9;j+=3){
			int x = i, y = j;
			set<char> st;
			bool check = true;
			for(int k =0;k<3;k++){
				for(int h = 0;h<3;h++){
					if(board[x+k][y+h]=='.') continue;
					if( st.find(board[x+k][y+h])!=st.end())){
						check = false;
						break;
					}
					st.insert(board[x+k][y+h]);
				}
			}
			if(!check) return false;
		}
	}
	return true;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
