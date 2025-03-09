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
	ListNode* head;
	stack<int> st;
	while(head!=nullptr){
		int temp = head->val;
		while(!st.empty() && temp> st.top()) st.pop();
		st.push(temp);
		head = head->next;
	}
	ListNode* curr = nullptr;
	while(!st.empty()){
		ListNode* temp = new List(st.top(), curr);
		curr = temp;
		st.pop();
	}
	return curr;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
