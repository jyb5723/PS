#include<iostream>
#include<queue>
#include<string.h>
#define N 6
using namespace std;

int n, ans;  char a[N][N]; bool st[25], vist[5][5], Move[5][5];
vector<pair<int, int>> v;  int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

bool bfs() {
	queue<pair<int, int>> q; int Cnt_ = 0;
	q.push({ v[0].first, v[0].second });
	while (!q.empty()) {
		int x1 = q.front().first; int y1 = q.front().second;
		q.pop(); Cnt_++;
		vist[x1][y1] = true;
		for (int i = 0; i < 4; i++) {
			int nx = x1 + dx[i]; int ny = y1 + dy[i];
			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
			if (!vist[nx][ny] && Move[nx][ny]) {
				vist[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
	if (Cnt_ >= 7)
		return true;
	return false;
}

void dfs(int idx, int cnt, int Lee) {
	if (cnt == 7) {
		if (Lee >= 4) 
			if (bfs()) ans++;
		memset(vist, false, sizeof(vist));
		return;
	}
	for (int i = idx + 1; i < 25; i++) {
		if (!st[i]) {
			st[i] = true;
			v.push_back({ i / 5,i % 5 });
			Move[i / 5][i % 5] = true;
			if (a[i / 5][i % 5] == 'S')
				dfs(i, cnt + 1, Lee + 1);
			else
				dfs(i, cnt + 1, Lee);
			v.pop_back();
			Move[i / 5][i % 5] = false;
			st[i] = false;
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> a[i][j];
	dfs(-1, 0, 0);

	cout << ans;

	return 0;
}