#include<iostream>
#include<algorithm>
#include<vector>

#define N 5 
#define W 13 
#define H 16

using namespace std;

int a[H][W], dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
int n, w, h, t;  vector<int> v; 

void dfs(int cnt) {
	if (cnt == n) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
		cout << '\n'; 
		return; 
	}
	for (int i = 0; i < w; i++) {
		v.push_back(i); 
		dfs(cnt + 1); 
		v.pop_back(); 
	}
	return; 
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t; 
	for (int tc = 1; tc <= t; tc++) {
		cin >> w >> h; 
		dfs(0); 
	}
	return 0;
}