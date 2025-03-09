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
#include<unordered_set>
#include<cmath>
#include<functional>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
struct option{
	bool operator()(long a, long b){
		return b < a;
	}
};
void solve(){
	int n = 1;
	/*
	 * 2 4 8
	 * 3 6 9 12
	 * 5 10 15 20
	 * */
	priority_queue<long, vector<long>, option> pq;
	unordered_set<long> st;
	vector<int> dx = {2l,3l,5l};
	st.insert(1);
	pq.push(1);
	long top =1;
	for(int i =0;i<n;i++){
		top = pq.top();
		pq.pop();
		for(int j=0;j< dx.size();j++){
			long temp = top * dx[j];
			if(st.find(temp) == st.end()){
				pq.push(temp);
				st.insert(temp);
			}
		}
	}
	cout<< static_cast<int>(top) <<endl;

}

void solve2(){
	int n = 1;
	vector<int> count(n,0);
	int index2 = 0, index3 = 0, index5 = 0;
	int value2 = 2, value3 = 3, value5 = 5;
	count[0] = 1;
	for(int i =1;i< n;i++){
		int valuetemp = min(value2, min(value3, value5));
		count[i] = valuetemp;
		if(valuetemp == value2){
			index2++;
			value2 = count[index2] *2;
		}
		if(valuetemp == value3){
			index3++;
			value3 = count[index3]*3;
		}
		if(valuetemp == value5){
			index5++;
			value5 = count[index5]*5;
		}
	}
	cout<< count[n-1]<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve2();
    return 0;
}
