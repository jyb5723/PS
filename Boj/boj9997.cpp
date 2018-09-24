#include<iostream>
#include<string>
#define N 26
using namespace std;

int a[N], n; string word[N];
int all, ans;

void dfs(int idx, int Sum) {
	if (idx == n) {
		if (Sum == all) {
			ans++; 
		}
		return; 
	}
	dfs(idx + 1, Sum | a[idx+1]); 
	dfs(idx + 1, Sum); 
	return; 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;  all = (1 << 26)-1; 

	for (int i = 0; i < n; i++) {
		cin >> word[i]; 
		int lng = word[i].length(); 
		for (int j = 0; j < lng; j++) {
			a[i] |= (1 << (word[i][j] - 'a'));
		}
	}
	dfs(-1, 0);
	cout << ans; 
	return 0;
}