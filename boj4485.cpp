// 2018 Y 09 M 19 D
// Minerba
#include<iostream>
#include<queue>
#include<algorithm>

#define N 126
#define INT 0x7fffffff

using namespace std;

typedef pair<int, int> pll;
typedef long long ll;

int n, dst[N][N]; priority_queue<pair<int, pll>> pq;
int map[N][N], t = 1;
int dx[] = { -1,1,0,0 }; int dy[] = { 0,0,-1,1 };

void s() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dst[i][j] = INT;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	while (1) {
		cin >> n; int Min = INT;
		if (!n) return 0;
		s();
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> map[i][j];

		dst[1][1] = map[1][1];
		pq.push({ -map[1][1],{ 1,1 } });

		while (!pq.empty()) {
			int x_ = pq.top().second.first;
			int y_ = pq.top().second.second;
			int cost = -pq.top().first;
			pq.pop();
			for (int i = 0; i < 4; i++) {
				int xx = x_ + dx[i]; int yy = y_ + dy[i];
				int n_dis = cost + map[xx][yy];
				if (xx < 1 || xx > n || yy < 1 || yy> n) continue;
				if (dst[xx][yy] > n_dis) {
					dst[xx][yy] = n_dis;
					pq.push({ -n_dis,{ xx, yy } });
				}
			}
		}
		cout << "Problem " << t++ << ": " << dst[n][n] << '\n';
	}
	return 0;
}