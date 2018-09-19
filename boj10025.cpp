#include<iostream>
#include<algorithm>

#define N 100001
#define M 1000001

using namespace std;

int a[M], p_s[M], n, k, Max;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x, c;
		cin >> c >> x;  // 물의 양과 좌표 
		a[x] = c;
		Max = max(x, Max);
	}
	p_s[0] = a[0];
	for (int i = 1; i <= Max; i++)
		p_s[i] = a[i] + p_s[i - 1];

	int ans = 0;
	for (int i = 0; i <= Max; i++) {
		int Sum = 0;
		if (i + k <= Max) Sum += p_s[i + k];
		else if (i + k > Max) Sum += p_s[Max];
		if (i - k > 0) Sum -= p_s[i - k - 1];
		ans = max(Sum, ans);
	}
	cout << ans;
	return 0;
}