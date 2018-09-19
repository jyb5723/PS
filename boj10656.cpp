// DeepSleep
#include<iostream>
#include<vector>
#define N 51
using namespace std;

char a[N][N]; int n, m, vist[N][N];   
vector<pair<int, int>> v;

bool r(int x, int y) {  
	if (y + 2 >= m) return false;
	if (a[x][y] == '#' || a[x][y + 1] == '#' || a[x][y + 2] == '#') return false;
	if (y - 1 >= 0 && a[x][y - 1] != '#') return false;   												
	return true;
}

bool c(int x, int y) {  
	if (x + 2 >= n) return false;
	if (a[x][y] == '#' || a[x + 1][y] == '#' || a[x + 2][y] == '#') return false;
	if (x - 1 >= 0 && a[x - 1][y] != '#') return false;   
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
			bool res_c = c(i, j);  bool res_r = r(i, j); 
			if (res_c || res_r) 
				v.push_back({ i + 1, j + 1 });
		}
	}
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << ' ' << v[i].second << '\n';
	return 0;
}