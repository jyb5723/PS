#include<iostream>
#include<vector>
#define N 201

using namespace std;

int n, m, a[N], ans; bool map_[N][N];
vector<int> v;

void dfs(int idx, int cnt) {
	if (cnt == 3) {
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < i; j++) {
				if (map_[v[i]][v[j]] || map_[v[j]][v[i]])
					return;
			}
		}
		ans++;
		return;
	}
	for (int i = idx + 1; i <= n; i++) {
		if (!map_[idx][i] && !map_[i][idx]) {
			v.push_back(i);
			dfs(i, cnt + 1);
			v.pop_back();
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	while (m--) {
		int x, y; cin >> x >> y;
		map_[x][y] = true, map_[y][x] = true;
	}
	dfs(0, 0);
	cout << ans << '\n';
	return 0;
}