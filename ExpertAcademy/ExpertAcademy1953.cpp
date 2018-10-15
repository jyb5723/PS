#include<iostream>
#include<queue>
#include<string.h>
#include<algorithm>

#define N 51

using namespace std;

int n, m, t, r, c, l, map[N][N]; bool Dir[N][N][4];
queue<pair<int, int>> q; bool chk[N][N]; int Cnt_; 
int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };

int clear() {
	memset(chk, false, sizeof(chk)); 
	memset(Dir, false, sizeof(Dir)); 
	memset(map, 0, sizeof(map)); 
	return Cnt_; 
}

void bfs() {
	int sz = q.size(); 
	for (int i = 0; i < sz; i++) {
		int x = q.front().first; int y = q.front().second; 
		q.pop(); 
		chk[x][y] = true; 
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; int ny = y + dy[i]; 
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 
			if (!chk[nx][ny] && Dir[nx][ny][(i + 2) % 4] && Dir[x][y][i]) {
				Cnt_++; 
				chk[nx][ny] = true; 
				q.push({ nx, ny }); 
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
		cin >> n >> m >> r >> c >> l;
		q.push({ r, c }); Cnt_ = 1; 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j]; 
				if (map[i][j] == 1) {
					for (int a = 0; a < 4; a++)
						Dir[i][j][a] = true; 
				}
				else if (map[i][j] == 2) {
					Dir[i][j][0] = true; 
					Dir[i][j][2] = true; 
				}
				else if (map[i][j] == 3) {
					Dir[i][j][1] = true; 
					Dir[i][j][3] = true; 
				}
				else if (map[i][j] == 4) {
					Dir[i][j][0] = true; 
					Dir[i][j][1] = true; 
				}
				else if (map[i][j] == 5) {
					Dir[i][j][1] = true; 
					Dir[i][j][2] = true; 
				}
				else if (map[i][j] == 6) {
					Dir[i][j][2] = true; 
					Dir[i][j][3] = true; 
				}
				else if (map[i][j] == 7) {
					Dir[i][j][0] = true; 
					Dir[i][j][3] = true; 
				}
			}
		}
		chk[r][c] = true; 
		for (int i = 0; i < l-1; i++) {
			bfs(); 
		}
		cout << '#' << tc << ' ' << Cnt_ << '\n'; 
		while (!q.empty()) q.pop(); 

	}
	return 0;
}