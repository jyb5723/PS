// DeepSleep
#include<iostream>
#include<vector>
#define N 51
using namespace std;

char a[N][N]; int n, m, vist[N][N];    // 0: 아무 단서도 안사용 1: 가로칸 단서로 사용   2: 세로칸 단서로 사용 
vector<pair<int, int>> v;

bool r(int x, int y) {  // 해당칸이 가로단서가 되는지 확인
	if (y + 2 >= m) return false;
	if (a[x][y] == '#' || a[x][y + 1] == '#' || a[x][y + 2] == '#') return false;
	if (y - 1 >= 0 && a[x][y - 1] != '#') return false;   // 경계를 벗어나지도 않으면서 왼쪽이 막혀있지도 않음 ( holy shat~ ) 												
	return true;
}

bool c(int x, int y) {  // 해당칸이 세로단서가 되는지 확인 
	if (x + 2 >= n) return false;
	if (a[x][y] == '#' || a[x + 1][y] == '#' || a[x + 2][y] == '#') return false;
	if (x - 1 >= 0 && a[x - 1][y] != '#') return false;   // 경계를 벗어나지도 않으면서 왼쪽이 막혀있지도 않음 ( holy shat~ ) 
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			bool res_c = c(i, j);  bool res_r = r(i, j); // 세로, 가로
			if (res_c || res_r) 
				v.push_back({ i + 1, j + 1 });
		}
	}
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << ' ' << v[i].second << '\n';
	return 0;
}