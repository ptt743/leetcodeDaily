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
 https://leetcode.com/problems/find-the-count-of-good-integers/description/?envType=daily-question&envId=2025-04-12

*/
void solve(){
	int n = 4,k= 1;
	int limit =(n+1)/2;
	unordered_map<string,bool> check;
	vector<int> pow(11,1);
	for(int i =1;i<=10;i++) pow[i]*= i * pow[i-1];
	function<int(string)> cal = [&](string s){
		if(s[0]=='0'){
			int first1  =1;
			int first2 = 1;
			int countz =0;
			for(int i =0;i<s.size();i++){
				if(s[i]=='0') countz++;
			}
			first1*=pow[countz];
			first2*=pow[countz-1];
			int count =1;
			for(int i =countz+1;i< s.size()+1;i++){
				if(i==s.size() || s[i]!=s[i-1]){
					first1 *= pow[count];
					first2 *= pow[count];
					count=1;
				} else count++;
			}
			return pow[n]/first1 - pow[n-1]/first2;

		} else {
			int first = 1;
			int count = 1;
			for(int i =1;i<s.size()+1;i++){
				if(i==s.size() || s[i]!=s[i-1]){
					first*=pow[count];
					count=1;
				} else count++;
			}
			return pow[n]/first;
		}
		return 0;
	};
	function<int(int,long long)> rc=[&](int index, long long curr)->int{
		if(index == limit){
			string temp;
			if(n%2!=0) temp  = to_string(curr/10);
			else temp = to_string(curr);
			reverse(temp.begin(), temp.end());
			if(temp=="0") return (curr%k==0);
			string res = to_string(curr) + temp;
			if((stoll(res)%k)!=0) return 0 ;
			sort(res.begin(), res.end());
			if(check[res]) return 0 ;
			cout<< res <<endl;
			check[res] = true;
			return cal(res);
		}
		int first = (index==0)?1:0;
		int res = 0;
		for(;first<=9;first++){
			res+=rc(index+1, curr*10+ first);
		}
		return res;
	};
	cout<<rc(0,0)<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
