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
#include <chrono>

#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
void solve(){
	int n = 5;
	int firstPlayer=0;
	int secondPlayer=4;

	long long initRow = 1<< n;
	vector<int> result;
	if(firstPlayer > secondPlayer) swap(firstPlayer, secondPlayer);
	for(long long state = initRow ; state >0; state--){
		int bits = __builtin_popcountll(state);
		int temp = n;
		bool check = false;
		int round =0;
		while(temp>1){
			if(temp == bits) {
				check = true;
				break;
			}
			round++;
			temp = (temp+1)/2;
		}
		if(!check) continue;
		if((1ll<<firstPlayer) & state ==0) continue;
		if((1ll<<secondPlayer) & state==0) continue;
		int countleft = 0;
		int countright =0;
		for(int i =0;i< n;i++){
			if((1ll<<i) & state !=0){
				if(i<firstPlayer) countleft++;
				if(i>secondPlayer) countright++;
			}
		}
		cout<< countleft<<" "<<countright<<endl;
		if(countleft!=countright) continue;
		cout<<"have"<<endl;
		
		result.push_back(round);
	}
	sort(result.begin(), result.end());

	cout<< result[0] <<" "<< result[result.size()-1]<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    using clock = std::chrono::steady_clock;      // hoặc high_resolution_clock
    auto start = clock::now();    
    solve();
    auto end   = clock::now();
    std::chrono::duration<double, std::milli> ms = end - start;
    std::cout << "Elapsed: " << ms.count() << " ms\n";
    return 0;
}
