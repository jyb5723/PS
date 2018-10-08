#include<iostream>
#include<algorithm>
#include<vector>

#define INT 0x7fffffff
#define N 11

using namespace std;

struct DATA {
	int x, y;
	DATA(int x = 0, int y = 0) :x(x), y(y) {}
};

char a[N][N]; int n, m;  vector<DATA> v; vector<int> dir;
DATA color[2];   bool Red, Blue;  char Color[] = { 'R','B' };
int ans = INT;

void simul(int dir) {
	if (!dir) {
		int idx = (color[0].x < color[1].x) ? 0 : 1;
		for (int i = 0; i < 2; i++) {
			int x = color[(idx + i) % 2].x; int y = color[(idx + i) % 2].y;
			a[x][y] = '.';
			while (a[x - 1][y] == '.' && x - 1 >= 0 && x < n && y >= 0 && y < m) x--;
			if (a[x - 1][y] == 'O') {
				color[(idx + i) % 2].x = x; color[(idx + i) % 2].y = y;
				if ((idx + i) % 2) Blue = true;
				else Red = true;
			}
			else {
				color[(idx + i) % 2].x = x; color[(idx + i) % 2].y = y;
				a[x][y] = Color[(idx + i) % 2];
			}
		}
	}
	else if (dir == 1) {
		int idx = (color[0].x > color[1].x) ? 0 : 1;
		for (int i = 0; i < 2; i++) {
			int x = color[(idx + i) % 2].x; int y = color[(idx + i) % 2].y;
			a[x][y] = '.';
			while (a[x + 1][y] == '.' && x >= 0 && x + 1 < n && y >= 0 && y < m) x++;
			if (a[x + 1][y] == 'O') {
				color[(idx + i) % 2].x = x; color[(idx + i) % 2].y = y;
				if ((idx + i) % 2) Blue = true;
				else Red = true;
			}
			else {
				color[(idx + i) % 2].x = x; color[(idx + i) % 2].y = y;
				a[x][y] = Color[(idx + i) % 2];
			}
		}
	}
	else if (dir == 2) {
		int idx = (color[0].y > color[1].y) ? 0 : 1;
		for (int i = 0; i < 2; i++) {
			int x = color[(idx + i) % 2].x; int y = color[(idx + i) % 2].y;
			a[x][y] = '.';
			while (a[x][y + 1] == '.' && x >= 0 && x < n && y >= 0 && y + 1 < m) y++;
			if (a[x][y + 1] == 'O') {
				color[(idx + i) % 2].x = x; color[(idx + i) % 2].y = y;
				if ((idx + i) % 2) Blue = true;
				else Red = true;
			}
			else {
				color[(idx + i) % 2].x = x; color[(idx + i) % 2].y = y;
				a[x][y] = Color[(idx + i) % 2];
			}
		}
	}
	else if (dir == 3) {
		int idx = (color[0].y < color[1].y) ? 0 : 1;
		for (int i = 0; i < 2; i++) {
			int x = color[(idx + i) % 2].x; int y = color[(idx + i) % 2].y;
			a[x][y] = '.';
			while (a[x][y - 1] == '.' && x >= 0 && x < n && y - 1 >= 0 && y < m) y--;
			if (a[x][y - 1] == 'O') {
				color[(idx + i) % 2].x = x; color[(idx + i) % 2].y = y;
				if ((idx + i) % 2) Blue = true;
				else Red = true;
			}
			else {
				a[x][y] = Color[(idx + i) % 2];
				color[(idx + i) % 2].x = x; color[(idx + i) % 2].y = y;
			}
		}
	}
	return;
}

void dfs(int cnt, int Before) {
	if (cnt == 10 || Red || Blue) {
		if (!Blue && Red)
			ans = min(cnt, ans);
		Red = false; Blue = false;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (Before != i) {
			int x = color[0].x; int y = color[0].y;  int xx = color[1].x; int yy = color[1].y;
			simul(i);
			dfs(cnt + 1, i);
			a[color[0].x][color[0].y] = '.'; a[color[1].x][color[1].y] = '.';
			a[x][y] = 'R'; a[xx][yy] = 'B';
			color[0].x = x; color[0].y = y;  color[1].x = xx; color[1].y = yy;
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'B')
				color[1].x = i, color[1].y = j;
			else if (a[i][j] == 'R')
				color[0].x = i, color[0].y = j;
		}
	}
	dfs(0, -1);
	if (ans > 10) cout << -1;
	else  cout << ans << '\n';
	return 0;
}