#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#define N 51
using namespace std;

int a[N][N]; bool clear;  int chk[N][N];
int Cnt = 0;
int dx[] = { -1,0,1,0 }; int dy[] = { 0,1,0,-1 };
int n, l, r;

void Move(int x, int y, int num, int People) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	while (!q.empty()) {
		int xx = q.front().first; int yy = q.front().second;
		q.pop();
		chk[xx][yy] = -1;
		a[xx][yy] = num;
		for (int i = 0; i < 4; i++) {
			int nx = xx + dx[i]; int ny = yy + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (chk[nx][ny] == People) {
				chk[nx][ny] = -1;
				q.push({ nx, ny });
			}
		}
	}
	return;
}

int main() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	int People = 0;  int Move_p = 0;
	while (!clear) {
		clear = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!chk[i][j]) {
					People++;
					queue<pair<int, int>> q;
					int t = a[i][j], p = 1;
					q.push({ i, j });

					while (!q.empty()) {
						int xx = q.front().first; int yy = q.front().second;
						q.pop();
						chk[xx][yy] = People;

						for (int s = 0; s < 4; s++) {
							int nx = xx + dx[s]; int ny = yy + dy[s];
							if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
							if (abs(a[nx][ny] - a[xx][yy]) >= l && abs(a[nx][ny] - a[xx][yy]) <= r && !chk[nx][ny]) {
								chk[nx][ny] = People;
								q.push({ nx, ny });
								p++;
								t += a[nx][ny];
								clear = false;
							}
						}
					}
					Move(i, j, t / p, People);
				}

			}
		}
		if (!clear) Move_p++;
		memset(chk, 0, sizeof(chk));
	}
	cout << Move_p << '\n';
	return 0;
}