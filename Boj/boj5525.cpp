// 2018 Y 09 M 19 D
// Minerba
#include <cstdio>
int n, m;
char c[1000005];
int main() {
	scanf("%d%d%s", &n, &m, c + 1);
	int ans = 0;
	int cnt = 0;
	for (int i = 1; i <= m; ++i) {
		if (c[i] == 'I' && c[i + 1] == 'O' && c[i + 2] == 'I') {
			++cnt;
			++i;     
		}
		else {
			if (cnt >= n)ans += cnt - n + 1;
			cnt = 0;
		}
	}
	printf("%d", ans);
}