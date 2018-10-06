#include<iostream>
#include<queue>
#define N 9
using namespace std;
typedef pair<int, int> pii;

bool chk[N][N];
int n, m, ans, dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
int a[N][N], tmp[N][N]; queue<pii> q, new_q;
vector<pii> v;


int clear() {
	int cnt_ = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!chk[i][j] && !a[i][j])
				cnt_++;
			chk[i][j] = false;
		}
	}
	return cnt_;
}

void bfs() {
	while (!q.empty()) {
		int x = q.front().first; int y = q.front().second;
		q.pop();
		chk[x][y] = true;
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i]; int yy = y + dy[i];
			if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
			if (!a[xx][yy] && !chk[xx][yy]) {
				chk[xx][yy] = true;
				q.push({ xx, yy });
			}
		}
	}
	return;
}

void dfs(int idx, int cnt) {
	if (cnt == 3) {
		bfs();
		ans = max(clear(), ans);
		q = new_q;
		return;
	}

	for (int i = idx + 1; i < v.size(); i++) {
		int x = v[i].first; int y = v[i].second;
		if (!a[x][y]) {
			a[x][y] = 1;
			dfs(i, cnt + 1);
			a[x][y] = 0;
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
			if (!a[i][j]) {
				v.push_back({ i, j });
			}
			if (a[i][j] == 2)   // 바이러스 
				q.push({ i, j });
		}
	}
	new_q = q;
	dfs(-1, 0);
	cout << ans << '\n';
	return 0;
}