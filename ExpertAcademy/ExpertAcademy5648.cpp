#include<iostream>
#include<map>
#include<vector>

#define N 4001
using namespace std;

struct DATA {
	int x, y, dir, power;
}d;

int t, n, Sum; DATA v[1001]; int chk[N][N]; bool chk1[N];
map<pair<int, int>, int> mp;	int siz;

void Erase() {
	for (int i = 0; i < siz; ++i) {
		if (chk1[i]) {
			chk1[i] = chk1[siz - 1];
			chk1[siz - 1] = 0;
			if (v[i].x >= 0 && v[i].x <= 4000 && v[i].y >= 0 && v[i].y <= 4000)
				Sum += v[i].power;
			v[i--] = v[--siz];
		}
	}
}

void Bomb() {
	int s = 0;
	for (int i = 0; i < siz; i++) {
		int x1 = v[i].x; int y1 = v[i].y; int dir1 = v[i].dir; int power1 = v[i].power;
		if (mp.count({ x1, y1 })) {
			chk1[i] = true, s++;
		}
		if (x1 >= 0 && x1 <= 4000 && y1 >= 0 && y1 <= 4000)
			chk[x1][y1] = 0;
	}
	if (s) Erase();
	mp.clear();
	return;
}

void simul() {
	for (int i = 0; i < siz; i++) {
		int x = v[i].x; int y = v[i].y; int dir = v[i].dir; int power = v[i].power;
		if (!dir) x++, v[i].x++; 		if (dir == 1) x--, v[i].x--;
		if (dir == 2) y--, v[i].y--;		if (dir == 3) y++, v[i].y++;
		if (v[i].x < 0 || v[i].x > 4000 || v[i].y < 0 || v[i].y > 4000) {   // 범위를 벗어나는 애들도 지워주자
			mp[{x, y}] = 1;  continue;
		}
		chk[x][y]++;
		if (chk[x][y] > 1)
			mp[{x, y}] = 1;
	}
	Bomb();
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> siz;  Sum = 0;
		for (int i = 0; i < siz; i++) {
			int x, y, dir, power;
			cin >> y >> x >> dir >> power;
			v[i].x = 2 * (x + 1000); v[i].y = 2 * (y + 1000); v[i].dir = dir;
			v[i].power = power;
		}
		for (int i = 1; i <= 4000; i++)
			simul();
		cout << '#' << tc << ' ' << Sum << '\n';
	}
	return 0;
}