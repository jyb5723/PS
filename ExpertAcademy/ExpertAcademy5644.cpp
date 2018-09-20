#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>

#define N 11
using namespace std;

int t, A, m, map[N][N];
int dx[] = { 0,-1,0,1,0 }, dy[] = { 0,0,1,0,-1 };  // 0 ,╩С, ©Л, го , аб
vector<int> a, b; int bc[9];    bool charge_map[N][N][9]; bool sr[9];   int Max = 0;  pair<int, int> p[2];

void clear() {
	memset(charge_map, 0, sizeof(charge_map));
	a.clear(), b.clear();
}

void dfs(int cnt, int Sum) {
	if (cnt == 2) {
		Max = max(Sum, Max);
		return;
	}
	for (int i = 1; i <= A; i++) {
		if (charge_map[p[cnt].first][p[cnt].second][i]) {
			if (sr[i])
				dfs(cnt + 1, bc[i]);
			else {
				sr[i] = true;
				dfs(cnt + 1, Sum + (bc[i]));
				sr[i] = false;
			}
		}
	}
	dfs(cnt + 1, Sum);
	return;
}

void Charge(int x, int y, int num, int c) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	for (int i = 0; i < c; i++) {
		int sz = q.size();
		for (int j = 0; j < sz; j++) {
			int x1 = q.front().first; int y1 = q.front().second;
			q.pop();
			charge_map[x1][y1][num] = true;
			for (int r = 1; r < 5; r++) {
				int nx = x1 + dx[r]; int ny = y1 + dy[r];
				if (nx < 1 || nx > 10 || ny < 1 || ny > 10) continue;
				if (!charge_map[nx][ny][num]) {
					charge_map[nx][ny][num] = true;
					q.push({ nx, ny });
				}
			}
		}
	}
	return;
}
int Simul() {
	int ans = 0;
	p[0].first = 1; p[0].second = 1; p[1].first = 10; p[1].second = 10;
	for (int i = 0; i < m + 1; i++) {
		Max = 0;
		p[0].first += dx[a[i]]; p[0].second += dy[a[i]];
		p[1].first += dx[b[i]]; p[1].second += dy[b[i]];
		dfs(0, 0);  ans += Max;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> m >> A;
		a.push_back(0);
		for (int i = 0; i < m; i++) {
			int x;  cin >> x;
			a.push_back(x);
		}

		b.push_back(0);
		for (int i = 0; i < m; i++) {
			int x;  cin >> x;
			b.push_back(x);
		}

		int x, y, c, power;
		for (int i = 1; i <= A; i++) {
			cin >> x >> y >> c >> power;
			Charge(y, x, i, c);
			bc[i] = power;
		}
		cout << '#' << tc << ' ' << Simul() << '\n';
		clear();
	}
	return 0;
}