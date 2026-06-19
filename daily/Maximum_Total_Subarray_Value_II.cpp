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
	vector<int> nums;
	int k;
	vector<vector<int>> st_max, st_min;
	vector<int> lg;
	function<void()> build_sparse_table = [&]() {
	    int n = nums.size();
	    st_max.assign(n, vector<int>(MAX_LOG));
	    st_min.assign(n, vector<int>(MAX_LOG));
	    lg.assign(n + 1, 0);

	    lg[1] = 0;
	    for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;

	    for (int i = 0; i < n; i++) {
		st_max[i][0] = nums[i];
		st_min[i][0] = nums[i];
	    }

	    for (int j = 1; j < MAX_LOG; j++) {
		for (int i = 0; i + (1 << j) <= n; i++) {
		    st_max[i][j] = max(st_max[i][j - 1], st_max[i + (1 << (j - 1))][j - 1]);
		    st_min[i][j] = min(st_min[i][j - 1], st_min[i + (1 << (j - 1))][j - 1]);
		}
	    }
	};

	function<int(int,int)> get_val=[&](int l, int r) {
	    int j = lg[r - l + 1];
	    int current_max = max(st_max[l][j], st_max[r - (1 << j) + 1][j]);
	    int current_min = min(st_min[l][j], st_min[r - (1 << j) + 1][j]);
	    return current_max - current_min;
	};
	function<long long(int,int)>  count_ge=[&](int n, int X) {
	    long long cnt = 0;
	    int l = 0; 
	    
	    for (int r = 0; r < n; r++) {
		// Mở rộng l lớn nhất có thể sao cho đoạn [l, r] vẫn có giá trị >= X
		while (l <= r && get_val(l, r) >= X) {
		    l++;
		}
		// Lúc này, mọi mảng con bắt đầu từ 0, 1, ..., l-1 và kết thúc tại r đều >= X
		cnt += l;
	    }
	    return cnt;
	};

	int n = nums.size();
	build_sparse_table();

	int low = 0, high = get_val(0, n - 1), V = 0;
	    
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (count_ge(n, mid) >= k) {
		    V = mid;      // Lưu kết quả hợp lệ
		    low = mid + 1; // Thử tìm V lớn hơn
		} else {
		    high = mid - 1;
		}
	}

	long long total_sum = 0;
	long long count_greater = 0;
	int l = 0;

	for (int r = 0; r < n; r++) {
		while (l <= r && get_val(l, r) > V) {
		    l++;
		}
		
		for (int i = 0; i < l; i++) {
		    total_sum += get_val(i, r);
		    count_greater++;
		}
	}

	total_sum += (k - count_greater) * (long long)V;

	return total_sum;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
