#include<iostream>
#include<queue>
#include<string.h>
#define max(a, b) ((a) > (b))?a:b
#define N 101
using namespace std;

struct DATA {
	int x, y, l, dir;
}d;

int n, m, k, t, flag[N][N], tmp[N][N], direction[N][N];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 }; 
queue<DATA> q; queue<pair<int, int>> chk_q;  

void Search() {
	int chk[N][N] = { 0, }; 
	while (!chk_q.empty()) {
		int x = chk_q.front().first; int y = chk_q.front().second; 
		chk_q.pop(); 
		if (!chk[x][y]) {
			chk[x][y] = true; 
			q.push({ x, y, tmp[x][y], direction[x][y] }); 
			tmp[x][y] = 0;  flag[x][y] = 0; direction[x][y] = -1;
		}
	}
	return;
}

void Move() {
	int sz = q.size();
	for (int i = 0; i < sz; i++) {
		int x = q.front().x; int y = q.front().y; int ll = q.front().l; int dir = q.front().dir;
		q.pop();

		int nx = x + dx[dir]; int ny = y + dy[dir];
		chk_q.push({ nx, ny }); 
		if (nx > 0 && nx < n - 1 && ny > 0 && ny < n - 1) {
			tmp[nx][ny] += ll;  
			if (flag[nx][ny] < ll) {
				flag[nx][ny] = ll;
				direction[nx][ny] = dir;
			}
		}
		else if (!nx || nx == n - 1 || !ny || ny == n - 1) {
			if (!dir) dir = 1; 
			else if (dir == 1) dir = 0;
			else if (dir == 2) dir = 3; 
			else if (dir == 3) dir = 2; 
			tmp[nx][ny] = ll / 2;  
			direction[nx][ny] = dir; 
		}
	}
	return;
}

int simul() {
	int ans = 0; 
	for (int i = 0; i < m; i++) {
		Search();
		Move(); 
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (tmp[i][j]) ans += tmp[i][j], tmp[i][j] = 0; 
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> m >> k;
		while (k--) {
			int x, y, n, d;
			cin >> x >> y >> n >> d; 
			tmp[x][y] = n; flag[x][y] = n; direction[x][y] = d-1; 
			chk_q.push({ x, y});
		}
		cout << '#' << tc << ' ' << simul() << '\n'; 
		memset(direction, 0, sizeof(direction)); 
		memset(tmp, 0, sizeof(tmp)); 
		memset(flag, 0, sizeof(flag)); 
		while (!chk_q.empty())chk_q.pop(); 
 	}
	return 0;
}