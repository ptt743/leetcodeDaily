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

 struct ListNode {
	int val;
      	ListNode *next;
      	ListNode() : val(0), next(nullptr) {}
     	ListNode(int x) : val(x), next(nullptr) {}
      	ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
ListNode* reverse(ListNode* root){
	ListNode* curr = root, pre = nullptr, next = nullptr;
	while(curr!=nullptr){
		next = curr->next;
		curr->next = pre;
		pre = curr;
		curr = next;
	}
	return pre;
}
void solve(){
	ListNode* temp = reverse(head);
        ListNode* pre;
        ListNode* copy = temp;
        int add = 0;

        while(temp!=nullptr){
            int tempVal = (int)(temp->val)*(int)2 + add;
            temp->val = (tempVal)%10;
            if(tempVal>=10) add = 1;
            else add = 0;
            pre = temp;
            temp = temp->next;
        }
        if(add==1){
            pre->next = new ListNode(1);
        }
        return reverse(copy);	
}

void solve2(){
	stack<int> st;
	while(head!=nullptr){
		st.push(head->val);
		head= head->next;
	}
	int keep = 0;

	ListNode* newHead = nullptr, * pre = nullptr;
	while(!st.empty()){
		int val = st.top()*2 + keep;
		newHead = new ListNode(val%10);
		newHead->next = pre;
		pre = newHead;

		if(val>=10) keep = 1;
		else keep = 0;
		st.pop();
		
	}
	if(keep==1){
		newHead = new ListNode(1);
		newHead->next = pre;
	}
	return newHead;
}

void solve3(){
	ListNode* curr = head;
	ListNode* pre = nullptr;
	while(curr!=nullptr){
		int temp = curr->val*2;
		if(temp<10){
			curr->val = temp;
		} else if( temp>=10 && pre!=nullptr){
			curr->val = (temp)%10;
			pre->val +=1;
		} else {
			head->val = temp%10;
			pre = new ListNode(1,curr);
			head = pre;
		}
		pre = curr;
		curr= curr->next;
	}
	return head;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
