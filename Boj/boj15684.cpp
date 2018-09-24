#include<iostream>
#define H 31
#define N 11
using namespace std;

int n, m, h, s; bool map[H][N], res;

void d() {
	for (int i = 1; i <= n; i++) {
		int pt = 1; int Cur = i;
		while (pt <= h) {
			if (Cur - 1 > 0 && map[pt][Cur - 1]) Cur--;
			else if (map[pt][Cur]) Cur++;
			pt++;
		}
		if (Cur != i) return;
	}
	res = true;
	return;
}

void dfs(int x, int cnt) {
	if (res) return;
	if (cnt == s) {
		d();
		return;
	}
	for (int i = x; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (!map[i][j]) {    // 현위치에 사다리가 없고
				if (!map[i][j - 1] && !map[i][j + 1]) {
					map[i][j] = true;
					dfs(i, cnt + 1);
					map[i][j] = false;
				}
			}
		}
	}
	return;
}

int main() {
	cin >> n >> m >> h;
	while (m--) {
		int x, y;
		cin >> x >> y;
		map[x][y] = true;
	}
	for (int i = 0; i <= 3; i++) {
		s = i;
		dfs(1, 0);
		if (res) {
			cout << i << ' ';
			return 0;
		}
	}
	cout << -1;
	return 0;
}