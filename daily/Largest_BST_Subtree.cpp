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
	int ans = 0;
        struct ValRet{
            int minVal;
            int maxVal;
            int maxSize;

        };
        function<ValRet(TreeNode*)> RC=[&](TreeNode* node){
            if(node== nullptr) return ValRet(INT_MAX, INT_MIN,0);
            ValRet left = RC(node->left);
            ValRet right = RC(node->right);
            if(left.maxVal < node->val && node->val < right.minVal){
                return ValRet(min(left.minVal,node->val), max(right.maxVal,node->val), left.maxSize + right.maxSize +1);
            }
            return ValRet(INT_MIN, INT_MAX,max(left.maxSize, right.maxSize));
            
        };
        return RC(root).maxSize;		
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
