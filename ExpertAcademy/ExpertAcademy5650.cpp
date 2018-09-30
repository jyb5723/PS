#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>

#define N 101
#define dbg cout << "C8\n";

using namespace std;

typedef pair<int, int> pii;

int t, n, a[N][N], dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
bool flag[N][N][4]; vector<pii> v[11];  queue<pair<int, int>> q;
int s_x, s_y, ans;

void Clear() {
	for (int i = 0; i <= 10; i++)
		v[i].clear();
	memset(a, 0, sizeof(a)); 
	memset(flag, false, sizeof(flag)); 
	ans = 0;
	return;
}

int Pin(int x, int y, int dir) {
	// 시작위치 x , y , 방향 : dir
	// 블랙홀일경우 
	int Score = 0; bool start = true; bool Worm = true;
	int nx = x + dx[dir]; int ny = y + dy[dir];
	while (1) {
		start = false; 
		if (!start && nx == x && ny == y) return Score; 
		if (a[nx][ny] == -1) return Score;

		//cout << nx << ' ' << ny << '\n';
		if (nx > n || nx < 1 || ny < 1 || ny > n)
			Score++, dir = (dir + 2) % 4;
		if (a[nx][ny] >= 1 && a[nx][ny] <= 5) {  // 블록이라면 
			if (flag[nx][ny][(dir + 2) % 4]) {
				for (int i = 0; i < 4; i++) {
					if ((dir + 2) % 4 != i && flag[nx][ny][i]) {
						dir = i; Score++;
						break;
					}
				}
			}
			else {
				dir = (dir + 2) % 4; 
				Score++; 
			}
		}
		else if (a[nx][ny] > 5 && Worm) { // 웜홀 
			int num = a[nx][ny];
			int Worm_1_x = v[num][0].first;  int Worm_1_y = v[num][0].second;
			int Worm_2_x = v[num][1].first;  int Worm_2_y = v[num][1].second;
			if (nx == Worm_1_x && ny == Worm_1_y) {
				nx = Worm_2_x; ny = Worm_2_y;
				Worm = false;
				continue;
			}
			else {
				nx = Worm_1_x; ny = Worm_1_y; 
				Worm = false; 
				continue; 
			}
		}
		Worm = true;
		nx += dx[dir]; ny += dy[dir];
	}
	return Score;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
				if (!a[i][j]) q.push({ i, j });

				else if (a[i][j] <= 4 && a[i][j] >= 1) {  // 블록

					if (a[i][j] == 1) {
						flag[i][j][0] = true; flag[i][j][1] = true;
						flag[i][j][2] = false; flag[i][j][3] = false;
					}
					else if (a[i][j] == 2) {
						flag[i][j][0] = false; flag[i][j][1] = true;
						flag[i][j][2] = true; flag[i][j][3] = false;
					}
					else if (a[i][j] == 3) {
						flag[i][j][0] = false;  flag[i][j][1] = false;
						flag[i][j][2] = true; flag[i][j][3] = true;
					}
					else if (a[i][j] == 4) {
						flag[i][j][0] = true; flag[i][j][1] = false;
						flag[i][j][2] = false; flag[i][j][3] = true;
					}
				}
				else if (a[i][j] > 5)
					v[a[i][j]].push_back({ i, j });
			}
		}
		while (!q.empty()) {
			int xx = q.front().first; int yy = q.front().second;
			q.pop();
			s_x = xx; s_y == yy;
			for (int i = 0; i < 4; i++) {
				int sc = Pin(xx, yy, i);
				ans = max(sc, ans);
			}
		}
		cout << '#' << tc << ' ' << ans << '\n';
		Clear();
	}
	return 0;
}