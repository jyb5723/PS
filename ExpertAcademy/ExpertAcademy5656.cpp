#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define N 5 
#define W 13 
#define H 16

using namespace std;
struct DATA {
	int x, y, cnt;
};
int a[H][W];
int n, w, h, t;  vector<int> v;  int ans;
int tmp[H][W]; int Origin;

void Recovery() {
	int cnt = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j]) cnt++;
			a[i][j] = tmp[i][j];
		}
	}
	Origin = min(Origin, cnt);
	return;
}

void Gravity() {
	queue<int> q;
	for (int i = 0; i < w; i++) {
		int x = h - 1;
		while (x >= 0) {
			if (a[x][i])
				q.push(a[x][i]), a[x][i] = 0;
			x--;
		}
		x = h - 1;
		while (!q.empty()) a[x][i] = q.front(), q.pop(), x--;
	}
	return;
}

void Break() {
	queue<DATA> q1;
	for (int i = 0; i < v.size(); i++) {   // 발사될 순서
		int col = v[i];   // 발사할 구슬의 줄 
		int x = 0;
		while (x < h) {
			if (a[x][col]) {
				q1.push({ x, col, a[x][col] });
				break;
			}
			x++;
		}
		while (!q1.empty()) {
			int x1 = q1.front().x;
			int y1 = q1.front().y;
			int p1 = (q1.front().cnt) - 1;
			q1.pop();
			a[x1][y1] = 0;
			int pt = 0;
			while (pt <= p1) {    // 살짝 주의 
				if (x1 + pt < h && a[x1 + pt][y1]) q1.push({ x1 + pt, y1 , a[x1 + pt][y1] }), a[x1 + pt][y1] = 0;
				if (y1 + pt < w && a[x1][y1 + pt]) q1.push({ x1,y1 + pt, a[x1][y1 + pt] }), a[x1][y1 + pt] = 0;
				if (x1 - pt >= 0 && a[x1 - pt][y1]) q1.push({ x1 - pt, y1, a[x1 - pt][y1] }), a[x1 - pt][y1] = 0;
				if (y1 - pt >= 0 && a[x1][y1 - pt]) q1.push({ x1, y1 - pt, a[x1][y1 - pt] }), a[x1][y1 - pt] = 0;
				pt++;
			}
		}
		Gravity();
	}
	return;
}

void dfs(int cnt) {
	if (cnt == n) {
		Break();
		Recovery();
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
		cin >> n >> w >> h;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> a[i][j], tmp[i][j] = a[i][j];
				if (a[i][j]) Origin++;
			}
		}
		dfs(0);
		cout << '#' << tc << ' ' << Origin << '\n';
	}

	return 0;
}