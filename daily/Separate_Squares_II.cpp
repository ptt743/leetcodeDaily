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
	vector<vector<int>> squares;
	vector<tuple<int, int, int, int>> events;
        set<int> xsSet;

	for (auto& sq : squares) {
            int x = sq[0], y = sq[1], l = sq[2];
            int xr = x + l;
            events.emplace_back(y, 1, x, xr);
            events.emplace_back(y + l, -1, x, xr);
            xsSet.insert(x);
            xsSet.insert(xr);
        }

        sort(events.begin(), events.end());
        vector<int> xs(xsSet.begin(), xsSet.end());
	int n = xs.size() -1;
	vector<int> count(4*n,0);
    	vector<int> covered(4*n,0);

	function<void(int,int,int,int,int,int)> modify=[&](int qleft, int qright, int qval, int left, int right, int pos) {
		if (xs[right + 1] <= qleft || xs[left] >= qright) {
		    return;
		}
		if (qleft <= xs[left] && xs[right + 1] <= qright) {
		    count[pos] += qval;
		} else {
		    int mid = (left + right) / 2;
		    modify(qleft, qright, qval, left, mid, pos * 2 + 1);
		    modify(qleft, qright, qval, mid + 1, right, pos * 2 + 2);
		}

		if (count[pos] > 0) {
		    covered[pos] = xs[right + 1] - xs[left];
		} else {
		    if (left == right) {
			covered[pos] = 0;
		    } else {
			covered[pos] = covered[pos * 2 + 1] + covered[pos * 2 + 2];
		    }
		}
    	};

	function<void(int,int,int)> update=[&](int qleft, int qright, int qval) {
        	modify(qleft, qright, qval, 0, n - 1, 0);
    	};
	vector<double> psum;
        vector<int> widths;
        double total_area = 0.0;
        int prev = get<0>(events[0]);

        for (auto& [y, delta, xl, xr] : events) {
            int len = covered[0];
            total_area += 1LL * len * (y - prev);
            update(xl, xr, delta);
            psum.push_back(total_area);
            widths.push_back(covered[0]);
            prev = y;
        }

	long long target = (long long)(total_area + 1) / 2;
        int i = lower_bound(psum.begin(), psum.end(), target) - psum.begin() - 1;
        double area = psum[i];
        int width = widths[i], height = get<0>(events[i]);

        return height + (total_area - area * 2) / (width * 2.0);
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
