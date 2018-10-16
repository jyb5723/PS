#include<iostream>
#include<vector>
#include<algorithm>
#define INT 0x3f3f3f3f
#define N 21
using namespace std;

char map[N][N]; int n, m;
vector<int> v; pair<int, int> coin[2];
int clear, ans = INT;

void Simul(int dir) {
	if (dir == 0) {
		for (int i = 0; i < 2; i++) {
			int x = coin[i].first; int y = coin[i].second;
			int nx = x - 1; int ny = y;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				clear += 1;
				continue;
			}
			if (map[nx][ny] == '#') continue;
			coin[i].first = nx; coin[i].second = ny;
		}
	}

	else if (dir == 1) {
		for (int i = 0; i < 2; i++) {
			int x = coin[i].first; int y = coin[i].second;
			int nx = x + 1; int ny = y;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				clear += 1;
				continue;
			}
			if (map[nx][ny] == '#') continue;
			coin[i].first = nx; coin[i].second = ny;
		}
	}

	else if (dir == 2) {
		for (int i = 0; i < 2; i++) {
			int x = coin[i].first; int y = coin[i].second;
			int nx = x; int ny = y - 1;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				clear += 1;
				continue;
			}
			if (map[nx][ny] == '#') continue;
			coin[i].first = nx; coin[i].second = ny;
		}
	}

	else if (dir == 3) {
		for (int i = 0; i < 2; i++) {
			int x = coin[i].first; int y = coin[i].second;
			int nx = x; int ny = y + 1;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				clear += 1;
				continue;
			}
			if (map[nx][ny] == '#') continue;
			coin[i].first = nx; coin[i].second = ny;
		}
	}
	return;
}

void dfs(int cnt) {
	if (cnt == 10 || clear) {
		if (clear == 1)
			ans = min(ans, cnt);
		clear = 0;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int x = coin[0].first; int y = coin[0].second;
		int xx = coin[1].first; int yy = coin[1].second;
		Simul(i);
		dfs(cnt + 1);
		coin[0].first = x; coin[0].second = y;
		coin[1].first = xx; coin[1].second = yy;
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;  int coin_ = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'o') {
				coin[coin_++] = { i, j };
			}
		}
	}
	dfs(0);
	if (ans <= 10)	cout << ans << '\n';
	else cout << -1 << '\n';
	return 0;
}