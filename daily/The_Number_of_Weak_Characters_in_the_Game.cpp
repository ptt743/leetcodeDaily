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
	vector<vector<int>> prop;
       	int n = prop.size();
	sort(prop.begin() , prop.end());
	multiset<int> stt;
	stack<pair<int,int>> st;
	int count = 0;
	for(int i = n-1;i>=0;i--){
		int second = prop[i][1];
		int first = prop[i][0];	
		if ((!st.empty() && st.top().first==first)){
		    pair<int,int> top = st.top();
		    st.pop();
		    auto it = stt.find(top.second);
		    stt.erase(it);
		    auto it2 = stt.upper_bound(second);
		    if(it2 != stt.end()){
			count++;	
		    }
		    st.push(top);
		    stt.insert(top.second);
		}else {
		    auto it2 = stt.upper_bound(second);
		    if(it2 != stt.end()){
			count++;	
		    }
		    st.push({first,second});
		    stt.insert(second);
		}
        }
	return count;	
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
