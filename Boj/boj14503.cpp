#include<iostream>
#define N 51
using namespace std;

int a[N][N], n, m; int r, c, d;
bool chk[N][N];  int dx[] = { -1,0,1,0 }; int dy[] = { 0,1,0,-1 };

void simul(int x, int y, int dir, int Rotate) {
	chk[x][y] = true;
	int nx = x + dx[(dir + 3) % 4]; int ny = y + dy[(dir + 3) % 4];  
	if (!chk[nx][ny] && !a[nx][ny]) {
		simul(nx, ny, (dir + 3) % 4, 0);
		return;
	}
	else {
		if (Rotate < 4) {
			simul(x, y, (dir + 3) % 4, Rotate + 1);
			return; 
		}
		else {
			int rx = x + dx[(dir + 2) % 4]; int ry = y + dy[(dir + 2) % 4];
			if (!a[rx][ry])  simul(rx, ry, dir, 0); 
		}
	}
	return;
}

int main() {
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> a[i][j];
	simul(r, c, d, 0);	int cnt_ = 0; 
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			if (chk[i][j]) cnt_++; 
	cout << cnt_; 
	return 0;
}