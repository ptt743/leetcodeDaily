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
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
void solve(){
	TreeNode* root;
	function<int(TreeNode*)> bfs=[&](TreeNode* root){
		int d = 0;
		queue<TreeNode*> qq;
		qq.push(root);
		while(!qq.empty()){
			d++;
			vector<TreeNode*> temp;
			while(!qq.empty()){
				TreeNode* node = qq.front();
				qq.pop();
				if(node->left) temp.push_back(node->left);
				if(node->right) temp.push_back(node->right);
				result[node->val] = make_pair(node, d); 
			}
			for(TreeNode* item : temp) qq.push(item);
			
		}
		return d;
	};
	int maxdepth = bfs(root);
	TreeNode* result = nullptr;
	int maxd = 0;
	int maxc = 0;
	function<int(TreeNode*,int)> dfs(TreeNode* root,int depth)->int{
		if(root == nullptr) return 0;
		int left = dfs(root->left,depth+1);
		int right = dfs(root->right, depth+1);
		int total = left + right + (depth == maxdepth);
		if((depth >= maxd && total > maxc)  || total >maxc) result = root;
		return total;
	}
	dfs(root, 1);

	return result;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
