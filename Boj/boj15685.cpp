#include<iostream>
#include<vector>

#define N 101

using namespace std;

int n, a[N][N], dx[] = { 0,-1,0,1 }, dy[] = { 1,0,-1,0 }, cnt, startX, startY;
vector<int> v;

bool Square(int x, int y) {
	if (x + 1 > 100 || y + 1 > 100) return false;
	if (a[x][y] && a[x + 1][y] && a[x][y + 1] && a[x+1][y+1]) return true;
	return false; 
}

void s(int cnt, int g) {
	if (cnt == g)
		return;
	int sz = v.size();
	for (int i = sz - 1; i >= 0; i--) {
		int nx = startX + dx[v[i]]; int ny = startY + dy[v[i]];
		a[nx][ny] = 1;
		startX = nx; startY = ny;
		v.push_back((v[i] + 1) % 4);
	}
	s(cnt + 1, g);
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n;
	while (n--) {
		int x, y, d, g;
		cin >> y >> x >> d >> g;
		a[x][y] = 1; a[x + dx[d]][y + dy[d]] = 1;
		startX = x + dx[d]; startY = y + dy[d];
		v.push_back((d + 1) % 4);
		s(0, g);
		v.clear();
	}
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) 
			if (Square(i, j)) cnt++; 		
	}
	cout << cnt; 
	return 0;
}