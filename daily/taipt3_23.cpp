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
	vector<int> diff={-40};
	int lower = -46;
	int upper = 53;
	int n = diff.size();	
	long long begin = 0;
	long long minVal = 0;
	long long maxVal = 0;
	
	for(int i =0;i< n;i++){
		begin = begin + diff[i];
		minVal = min(begin, minVal);
		maxVal = max(begin, maxVal);
	}
	long long distance = maxVal - minVal;
	/*
		choosing random begin of sequence is x =>  maxValue of sequence can be x+ distance
		but we have range [lower, upper]
		<=> x >= lower and x+ distance <= upper 
		<=> lower<= x <= upper - distance
		so we have the number of ways to choose x is upper - distance - lower + 1
		FIND WAYS TO CHOOSE FIRST NUMBER
	*/
	int result = upper -  distance - lower+1 ;
	if( result <=0 ) result =0;
	cout<< result <<endl;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
