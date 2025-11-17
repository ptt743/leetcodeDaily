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
	int k;
	int n = s.size();
	function<unsigned(char)> bit = [&](char c){ return 1u<< (c - 'a'); };

	unordered_map<unsigned, int> dpkeep, dpuse;
	dpkeep.reserve(1<<12);
	dpuse.reserve(1<<12);
	dpkeep[0] = 0;

	auto relax = [](unordered_map<unsigned,int>& mp, unsigned mask, int val){
                auto it = mp.find(mask);
                if (it == mp.end()) mp.emplace(mask, val);
                else it->second = max(it->second, val);
        };

	for(int i = 0;i< n;i++){
		unordered_map<unsigned,int> nxtkeep, nxtuse;
		nxtkeep.reserve(dpkeep.size()*2 + 64);
		nxtuse.reserve((dpuse.size() + dpkeep.size())*26 + 64);

		for(auto &[mask,done] : dpkeep){
			unsigned nb = bit(s[i]);
			unsigned m2 = mask| nb;
			if(popcount(m2)<=k){
				relax(nxtkeep, m2, done);
			} else {
				relax(nxtkeep, nb, done+1);
			}

			for(int j = 0;j<26;j++){
				unsigned nb2 = 1u<<j;
				unsigned m3 = mask|nb2;
				if(popcount(m3)<=k){
					relax(nxtuse, m3, done);
				} else {
					relax(nxtuse, nb2, done+1);
				}
			}
		}

		for(auto&[mask,done]: dpuse){
			unsigned nb = bit(s[i]);
			unsigned m2 = mask | nb;
			if(popcount(m2) <=k){
				relax(nxtuse, m2, done);
			} ele {
				relax(nxtuse, nb, done+1);
			}
		}

		dpkeep.swap(nxtkeep);
		dpuse.swap(nxtuse);
	}
	int best =0;
	for(auto &[_,done]: dpkeep) best = max(best, done);
	for(auto &[_,done] : dpuse) best = max(best, done);
	return best+1;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
