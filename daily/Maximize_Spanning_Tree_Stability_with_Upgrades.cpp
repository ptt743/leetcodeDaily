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


struct DSU {
    vector<int> parent;
    
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]); 
    }

    bool union_sets(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int max_stability(int n, vector<vector<int>>& edges, int k) {
        DSU dsu_check(n);
        int components = n;

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], m = edge[3];
            if (m == 1) {
                if (dsu_check.union_sets(u, v)) {
                    components--;
                } else {
                    return -1;
                }
            }
        }

        // 1.2: Dùng thêm các cạnh tự do để kiểm tra tính liên thông của toàn đồ thị
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], m = edge[3];
            if (m == 0) {
                if (dsu_check.union_sets(u, v)) {
                    components--;
                }
            }
        }

        if (components > 1) return -1;

        // Bước 2: Khởi tạo khoảng tìm kiếm nhị phân
        int low = 0;
        int high = 0;
        for (const auto& edge : edges) {
            high = max(high, edge[2] * 2); // Sức mạnh tối đa có thể đạt được
        }
        
        int ans = -1;

        // Hàm Lambda để kiểm tra xem mức độ ổn định X có khả thi không
        auto check = [&](int X) {
            DSU dsu(n);
            int comps = n;
            int upgrades = 0;

            // 2.1: Bắt buộc phải thêm các cạnh có m == 1
            for (const auto& edge : edges) {
                int u = edge[0], v = edge[1], s = edge[2], m = edge[3];
                if (m == 1) {
                    if (s < X) return false; // Cạnh bắt buộc không đạt mức X -> Sai
                    if (dsu.union_sets(u, v)) comps--;
                }
            }

            // 2.2: Thêm các cạnh tự do (m == 0) đã đủ điều kiện (s >= X)
            for (const auto& edge : edges) {
                int u = edge[0], v = edge[1], s = edge[2], m = edge[3];
                if (m == 0 && s >= X) {
                    if (dsu.union_sets(u, v)) comps--;
                }
            }

            // 2.3: Thêm các cạnh tự do cần nâng cấp (s < X nhưng s * 2 >= X)
            for (const auto& edge : edges) {
                int u = edge[0], v = edge[1], s = edge[2], m = edge[3];
                if (m == 0 && s < X && s * 2 >= X) {
                    if (dsu.union_sets(u, v)) {
                        comps--;
                        upgrades++;
                    }
                }
            }

            // Mức X khả thi nếu đồ thị là 1 cây liên thông và số lượt nâng cấp không vượt quá k
            return (comps == 1) && (upgrades <= k);
        };

        // Bước 3: Vòng lặp tìm kiếm nhị phân
        while (low <= high) {
            int mid = low + (high - low) / 2; // Tránh tràn số (overflow)
            if (check(mid)) {
                ans = mid;       // Lưu kết quả hợp lệ
                low = mid + 1;   // Cố gắng tìm mức ổn định cao hơn
            } else {
                high = mid - 1;  // Mức ổn định mid không khả thi, giảm xuống
            }
        }

        return ans;
    }
};
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
