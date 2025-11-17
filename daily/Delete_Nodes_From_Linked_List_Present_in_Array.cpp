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
	int n = nums.size();
        set<int> st;
        for(int i = 0;i< n;i++){
            st.insert(nums[i]);
        }
        while(head!=nullptr && st.find(head->val)!=st.end()){
            head = head->next;
        }
        ListNode* headres = head;
        ListNode* pre = head;
        head = head->next;
        while(head!=nullptr){
            if(st.find(head->val)==st.end()){
                pre->next = head;
                pre = head;
            }
            head = head->next;
        }
        if(pre->next!=nullptr) pre->next = nullptr;
    return headres;		
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
