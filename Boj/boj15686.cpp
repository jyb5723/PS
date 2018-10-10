#include<iostream>
#include<algorithm>
#include<vector>
#define N 51
#define INT 0x7fffffff
using namespace std;

struct DATA {
	int x, y;
}d;

int n, m, a[N][N], ans_ = INT;
vector<DATA> r;
vector<DATA> v; vector<DATA> s;

int calc() {
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		int house_x = s[i].x; int house_y = s[i].y;
		int chiken_d = INT;
		for (int j = 0; j < r.size(); j++) {
			int chicken_x = r[j].x; int chicken_Y = r[j].y;
			chiken_d = min(chiken_d, abs(house_x - r[j].x) + abs(house_y - r[j].y));
		}
		ans += chiken_d;
	}
	return ans;
}

void dfs(int idx, int cnt) {
	if (cnt == m) {
		ans_ = min(ans_, calc());
		return;
	}

	for (int i = idx + 1; i < v.size(); i++) {
		d.x = v[i].x; d.y = v[i].y;
		r.push_back(d);
		dfs(i, cnt + 1);
		r.pop_back();
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) {
				d.x = i; d.y = j;
				s.push_back(d);
			}
			else if (a[i][j] == 2) {
				d.x = i; d.y = j;
				v.push_back(d);
			}
		}
	}
	dfs(-1, 0);
	cout << ans_;
	return 0;
}