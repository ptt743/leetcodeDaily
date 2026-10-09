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
	  string s;
    int n = s.size();
    stack<char> st;
    for (char c : s) {
        if (c == ')') {
            string temp = "";
            while (!st.empty() && st.top() != '(') {
                temp += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // bỏ qua dấu '('
            for (char ch : temp) {
                st.push(ch); // đẩy lại vào stack theo thứ tự đã đảo ngược
            }
        } else {
            st.push(c);
        }
    }
    
    string result = "";
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
