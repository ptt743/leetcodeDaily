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


class ExamRoom {
private:
    int maxS;
    set<int> st;

public:
    ExamRoom(int n) {
        maxS = n;
    }
    
    int seat() {
        if(st.size()==0){
            st.insert(0);
            return 0;
        }
        int pre = -1;
        int dis = *st.begin();
        int ind = 0;
        for(const int& item : st ){
            if(pre !=-1){
                int temp = ( item - pre )/2;
                if(temp > dis){
                    dis = temp;
                    ind = pre + temp;
                }

            }
            pre = item;
        }
        if((maxS-1 - pre)> dis){
            dis = (maxS-1-pre);
            ind = pre + dis;
        }
        st.insert(ind);
        return ind;
    }
    
    void leave(int p) {
        st.erase(p);
    }
};

void solve(){
			
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
