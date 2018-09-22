#include<iostream>
#include<algorithm>
#define INT 0x7fffffff
using namespace std;

int a[12], Sum[5], Num[5]; int ans = INT;
void dfs(int idx) {
	if (idx == 12) {
		int Min = INT; int Max = 0;
		for (int i = 1; i <= 4; i++)
			Min = min(Min, Sum[i]), Max = max(Max, Sum[i]);
		ans = min(Max - Min, ans);
		return;
	}
	for (int i = 1; i <= 4; i++) {
		if (Num[i] < 3) {
			Num[i]++;
			Sum[i] += a[idx];
			dfs(idx + 1);
			Num[i]--;
			Sum[i] -= a[idx];
		}
	}
	return;
}
int main() {
	for (int i = 0; i < 12; i++)
		cin >> a[i];
	dfs(0);
	cout << ans;
	return 0;
}