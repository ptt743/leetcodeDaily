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
	struct ListNode{
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
 		ListNode(int x, ListNode *next) : val(x), next(next) {}
	}
	vector<ListNode*> lists;
	priority_queue<ListNode*, vector<ListNode*>, decltype([](ListNode* a, ListNode* b){
				return a->val > b->val;
			})> pq;
	int n = lists.size();
	for(int i = 0;i< n;i++)
        if(lists[i]!=nullptr)
            pq.push(lists[i]);

	ListNode* root = nullptr;
    	ListNode* te = nullptr;
	while(!pq.empty()){
		ListNode* top = pq.top();
		pq.pop();
		if(root == nullptr){
           		root = top;
            		te = root;
        	} else {
            		te->next = top;
            		te = te->next;
        	}
        

		ListNode* temp = top->next;
		top->next = nullptr;
		if(temp!=nullptr) pq.push(temp);
	}
	return root;	
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
