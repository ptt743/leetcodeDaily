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
	int nums;
	vector<vector<string>> events;
	function<bool(vector<string>&, vector<string>&)> option=[&](vector<string>&a, vector<string>&b){
		return stoi(a[1]) < stoi(b[1]) || (stoi(a[1])==stoi(b[1]) && a[0]=="OFFLINE");
	};
	sort(events.begin(), events.end(), option);
	deque<pair<string,int>> dq;

	int n = events.size();
	vector<int> count(nums,0);
	multiset<string> st;
	int all = 0;
	for(int i = 0;i< n;i++){
		if(events[i][0] =="OFFLINE"){
			dq.push_back({events[i][2], stoi(events[i][1]) + 60});
            st.insert(events[i][2]);
		} else{
			int ts = stoi(events[i][1]);
			while(!dq.empty() && dq.front().second<= ts){
				string id = dq.front().first;
				auto it = st.find(id);
				st.erase(it);
				dq.pop_front();
			}
			string data = events[i][2];
			if(data=="ALL"){
				for(int k = 0;k< nums;k++){
					count[k]++;
				}	
			} else if ( data =="HERE"){
				for(int k = 0;k< nums;k++){
					if(st.find(to_string(k))==st.end()){
						count[k]++;
					}
				}
			} else {
				int len = data.size();
				string currId = "";
				for(int k = 0;k <=len;k++){
					if(k==len || data[k]==' '){
                        			int tempId = stoi(currId.substr(2));
						count[tempId]++;
						currId = "";
					}else currId +=data[k];
				}
			}
			
		}

	}
	return count;
	
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
