#include<iostream>
#include<queue>
#define N 101
using namespace std;

int map[N][N], dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
int n, k, x, y, dir;   char cnt[10001]; deque<pair<int, int>> q; 

bool simul() {
	int nx = q.front().first+dx[dir]; int ny = q.front().second + dy[dir];
	if (nx < 1 || nx > n || ny < 1 || ny > n) return false;   // 맵 바깥을 벗어나는 경우 
	if (map[nx][ny] == 3) {  // 사과가 있는 경우
		q.push_front({ nx, ny }); 
		map[nx][ny] = 1; 
		return true; 
	}
	else if (map[nx][ny] == 1) return false;   // 몸통인 경우
	else {
		int tmp_x = q.front().first; int tmp_y = q.front().second; 
		int nx = tmp_x + dx[dir]; int ny = tmp_y + dy[dir]; 
		map[tmp_x][tmp_y] = 0;	map[nx][ny] = 1; 
		q.pop_front(); 
		int sz = q.size();
		q.push_back({ nx, ny }); 
		for (int i = 0; i < sz; i++) {
			int xx = q.front().first; int yy = q.front().second; 
			q.pop_front();
			map[xx][yy] = 0; map[tmp_x][tmp_y] = 1; 
			q.push_back({ tmp_x,tmp_y }); 
			tmp_x = xx; tmp_y = yy; 
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> k;
	while (k--) {
		int x, y; cin >> x >> y;
		map[x][y] = 3;
	}
	cin >> k;
	while (k--) {
		int x; char inp;
		cin >> x >> inp;
		cnt[x] = inp;
	}
	q.push_front({ 1,1 }); 
	map[1][1] = 1; 
	int sec = 0;  dir = 1;
	while (1) {
		if (!simul()) {
			sec++; 
			break; 
		}
		sec++; 
		if (cnt[sec] == 'L') dir = (dir + 3) % 4;
		if (cnt[sec] == 'D') dir = (dir + 1) % 4;
	}
	cout << sec << '\n'; 
	return 0;
}