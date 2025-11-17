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
	vector<int> height={1,8,6,2,5,4,8,3,7};
	int n = height.size();

	vector<int> d(n,0);
	deque<int> dq;
	dq.push_back(n-1);
	int result = 0;
	for(int i = n-2;i>=0;i--){
		int right = dq.front();
		int volume = (right - i)*min(height[i], height[right]) + d[right];
		cout<<  i<<" "<<volume<<endl;
		d[i] = volume;
		result = max(result, volume);
		while(!dq.empty() && height[i]>height[dq.back()]) dq.pop_back();
		dq.push_back(i);
	}
	cout<< result <<endl;

}

void solve2(){
	vector<int> height = {1,8,6,2,5,4,8,3,7};
	int n = height.size();

	int left = 0, right = n-1;
	int result = 0;
	while(left< right){
		int w = (right - left);
		int h = min(height[left], height[right]);
		result = max(result, h*w);
		if(height[left]<height[right]) left++;
		else right--;
	}
	cout<< result <<endl;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve2();
    return 0;
}
