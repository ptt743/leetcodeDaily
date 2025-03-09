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
	string word="abc";
	int n = word.size();
	string format = "abc";
	int first = 0, second = 0;
	int result = 0;
	for(;first< n;){
		if(word[first]== format[second]){
			first++;
		} else {
			result++;
		}
		second = (second + 1) % 3;
	}
	result += 3 - (word[n-1] - 'a'+1);
	cout<< result<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
