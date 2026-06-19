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
	int hour;
	int minutes;
	double number = (double)minutes/5;
    	double h = hour + (double)minutes/60;
	double temp =  max((double)h, number) - min((double)h, number);
    	double mul = min(temp, (double)12 - temp);

	double res = 30 * mul;
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
