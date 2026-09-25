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
  vector<int> count(10, 0);
    for (int d : digits) {
        count[d]++;
    }
    int totalValidNumbers = 0;
    for (int u = 0; u <= 8; u += 2) {
        if (count[u] == 0) continue; // Nếu không có số này trong mảng thì bỏ qua
        count[u]--; // Tạm lấy ra 1 số u để dùng cho hàng đơn vị
        for (int h = 1; h <= 9; h++) {
            if (count[h] == 0) continue;
            count[h]--; // Tạm lấy ra 1 số h để dùng cho hàng trăm
            for (int t = 0; t <= 9; t++) {
                if (count[t] > 0) {
                    totalValidNumbers++; 
                }
            }
            count[h]++; // Trả lại số h để thử trường hợp khác
        }
        count[u]++; // Trả lại số u để thử trường hợp khác
    }
    return totalValidNumbers;		
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
