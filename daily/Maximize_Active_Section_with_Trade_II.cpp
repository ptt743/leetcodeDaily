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
        vector<vector<int>>& queries;
  	    int n = s.size();
        int totalOnes = count(s.begin(), s.end(), '1');

        // Lấy các đoạn '0': zs[i], ze[i] = start, end
        vector<int> zs, ze;
        for (int i = 0; i < n; ) {
            if (s[i] == '0') {
                int j = i;
                while (j < n && s[j] == '0') j++;
                zs.push_back(i); ze.push_back(j - 1); i = j;
            } else i++;
        }
        int m = zs.size();
        auto len = [&](int i){ return ze[i] - zs[i] + 1; };

        // Sparse table cho pairSum[i] = len(i) + len(i+1)
        int psN = max(0, m - 1);
        vector<vector<int>> sp;
        vector<int> lg;
        if (psN > 0) {
            lg.assign(psN + 1, 0);
            for (int i = 2; i <= psN; i++) lg[i] = lg[i/2] + 1;
            int K = lg[psN] + 1;
            sp.assign(K, vector<int>(psN));
            for (int i = 0; i < psN; i++) sp[0][i] = len(i) + len(i+1);
            for (int k = 1; k < K; k++)
                for (int i = 0; i + (1<<k) <= psN; i++)
                    sp[k][i] = max(sp[k-1][i], sp[k-1][i + (1<<(k-1))]);
        }
        auto rangeMax = [&](int lo, int hi){
            int k = lg[hi - lo + 1];
            return max(sp[k][lo], sp[k][hi - (1<<k) + 1]);
        };

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto& qy : queries) {
            int l = qy[0], r = qy[1], gain = 0;
            if (m > 0) {
                int p  = lower_bound(ze.begin(), ze.end(), l) - ze.begin();
                int q  = (int)(upper_bound(zs.begin(), zs.end(), r) - zs.begin()) - 1;
                if (p < m && q >= 0 && p < q) {          // cần >= 2 đoạn '0'
                    int clipP = ze[p] - max(zs[p], l) + 1;
                    int clipQ = min(ze[q], r) - zs[q] + 1;
                    if (q == p + 1) {
                        gain = clipP + clipQ;
                    } else {
                        gain = max(clipP + len(p+1), len(q-1) + clipQ);
                        if (p + 1 <= q - 2)
                            gain = max(gain, rangeMax(p+1, q-2));
                    }
                }
            }
            ans.push_back(totalOnes + gain);
        }
        return ans;	
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
