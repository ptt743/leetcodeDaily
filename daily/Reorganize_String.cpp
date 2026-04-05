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
	vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;

        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                if (count[i] > (s.length() + 1) / 2) return ""; 
                pq.push({count[i], i + 'a'});
            }
        }

        string res = "";
        while (pq.size() >= 2) {
            auto [freq1, char1] = pq.top(); pq.pop();
            auto [freq2, char2] = pq.top(); pq.pop();

            res += char1;
            res += char2;

            if (--freq1 > 0) pq.push({freq1, char1});
            if (--freq2 > 0) pq.push({freq2, char2});
        }

        if (!pq.empty()) {
            res += pq.top().second;
        }
        return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
