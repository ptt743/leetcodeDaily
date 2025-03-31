#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<cmath>
#include<functional>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
const int LIMIT = 1e6 + 5;
const int mod = 1e9 +7;
vector<int> spf(LIMIT);

void sieve_spf() {
    for (int i = 2; i < LIMIT; i++) spf[i] = i; 
    for (int i = 2; i * i < LIMIT; i++) {
        if (spf[i] == i) { 
            for (int j = i * i; j < LIMIT; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

int prime_score(int n) {
    unordered_set<int> prime_factors;
    while (n > 1) {
        prime_factors.insert(spf[n]);    
	n /= spf[n];
	cout<< n <<endl;
    }
    return prime_factors.size();
}

long long powerMod(long long base, long long exp, int mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
	exp /= 2;
    }
    return result;
}

bool option(pair<long long, long long>& a, pair<long long, long long> b){
	return a.first < b.first;
}

void solve(){
    sieve_spf();
    vector<int> nums= {19,12,14,6,10,18};
    int k = 3;
    int n = nums.size();
    vector<int> score;
    for(int i =0;i< n;i++){
	    score.push_back(prime_score(nums[i]));
    }
    stack<int> left, right;
    vector<long long> left_count(n,0), right_count(n,0);
    for(int i =0;i< n;i++){
	while(!left.empty() && score[i]> score[left.top()]) left.pop();
	if(left.empty()) left_count[i] = i+1;
	else left_count[i] = i - left.top();
	left.push(i);
    }

    for(int i = n-1;i>=0;i--){
	while(!right.empty() && score[i]>= score[right.top()]) right.pop();
	if(right.empty()) right_count[i] = n - i;
	else right_count[i] = right.top() - i;
	right.push(i);
    }

    vector<pair<long long, long long>> temp;
    for(int i =0;i< n;i++){
	temp.push_back(make_pair(nums[i], left_count[i] * right_count[i]));
    }
    sort(temp.begin(), temp.end(), option);
    int index = n-1;
    long long result = 1ll;
    while(k){
	long long count = min((long long)k, temp[index].second);
	result = ((result%mod)*(powerMod(temp[index].first, count,1e9+7)%mod))%mod;
	k -=count;
	if(k<=0) break;
	index--;
    }

    cout<< result<<endl;

    
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
