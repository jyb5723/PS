//2019Y 03M 27D
//Minerb

#include<iostream>
#include<queue>
#define N 17
using namespace std;

int n, ans, ar[N][N], vist[N][N];
const int dx[] = { 0, 1, 1 };
const int dy[] = { 1, 0, 1 };

struct re {
	int x, y, dir;
}d;
bool chk(int x, int y) {
	if (x + 1 > n || y + 1 > n) return 0;
	if (ar[x + 1][y] || ar[x][y + 1] || ar[x + 1][y + 1]) return 0;
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> ar[i][j];

		}
	}
	queue<re> q;
	q.push({ 1, 2, 0 });

	while (!q.empty()) {
		int xx = q.front().x; int yy = q.front().y;
		int dd = q.front().dir;

		q.pop();

		if (xx == n && yy == n) {
			ans++;
			continue;
		}
		if (dd != 2) {
			int nx = xx + dx[dd]; int ny = yy + dy[dd];
			int nx1 = xx + dx[2]; int ny1 = yy + dy[2];

			if (nx <= n && ny <= n && !ar[nx][ny]) {
				q.push({ nx, ny, dd });
			}
			if (nx1 <= n && ny1 <= n && chk(xx, yy)) {
				q.push({ nx1, ny1, 2 });
			}
		}
		else {
			int nx = xx + dx[dd]; int ny = yy + dy[dd];

			if (nx <= n && ny <= n && chk(xx, yy)) {
				q.push({ nx, ny, dd });
			}
			for (int i = 0; i < 2; i++) {
				int nxx = xx + dx[i]; int nyy = yy + dy[i];
				if (nxx > n || nyy > n) continue;
				if (!ar[nxx][nyy]) {
					q.push({ nxx, nyy, i });
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}