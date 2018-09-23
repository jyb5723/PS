#include<iostream>
#include<queue>
#include<string.h>

#define N 601
using namespace std;
int n, m, t, k, Cur_time; int a[N][N], tmp[N][N];  int vist[N][N];
priority_queue<pair<int, pair<int, int>>> pq;
priority_queue<pair<int, pair<int, int>>> pq1;
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

void Cell() {
	int sz = pq.size();
	for (int s = 0; s < sz; s++) {
		if (Cur_time >= -pq.top().first + 1) {
			int x = pq.top().second.first; int y = pq.top().second.second;
			pq.pop();
			tmp[x][y]--;
			if (!tmp[x][y])
				vist[x][y] = -1;
			else {
				pq.push({ -(Cur_time),{ x, y } });
			}
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i]; int ny = y + dy[i];
				if (!vist[nx][ny] && a[nx][ny] < a[x][y]) {

					a[nx][ny] = tmp[nx][ny] = a[x][y];
					pq1.push({ a[x][y],{ nx, ny } });

				}
			}
		}
		else
			break;
	}
	return;
}
void simul() {
	for (Cur_time = 1; Cur_time <= k; Cur_time++) {
		Cell();
		while (!pq1.empty()) {
			int x1 = pq1.top().second.first; int y1 = pq1.top().second.second;
			int val = pq1.top().first;
			pq1.pop();
			if (!vist[x1][y1]) {
				vist[x1][y1] = val;
				pq.push({ -(Cur_time + val) ,{ x1, y1 } });
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> m >> k;
		for (int i = 300; i < 300 + n; i++) {
			for (int j = 300; j < 300 + m; j++) {
				cin >> a[i][j];
				tmp[i][j] = a[i][j];
				if (a[i][j] >= 1)
					pq.push({ -a[i][j],{ i, j } }), vist[i][j] = a[i][j];
			}
		}
		simul();
		cout << '#' << tc << ' ' << pq.size() << '\n';
		memset(vist, 0, sizeof(vist));
		memset(a, 0, sizeof(a));
		memset(tmp, 0, sizeof(tmp));
		while (!pq.empty())
			pq.pop();
		while (!pq1.empty())
			pq1.pop();
	}
	return 0;
}