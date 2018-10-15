#include<iostream>
#include<vector>
#define N 9
using namespace std; 

int n, m, a[N][N], tmp[N][N];  bool Camera[N][N][4];
int dx[] = {-1,0,1,0}; int dy[] = {0,1,0,-1}; // 상 , 우, 하, 좌 
vector<pair<int, int>> v;  vector<int> dir;   // 명령어 테이블 


void dfs(int cnt) {
	if (cnt == v.size()) {
		for (int i = 0; i < dir.size(); i++) {
			cout << dir[i] << ' '; 
		}
		cout << '\n'; 
		return; 
	}
	for (int i = 0; i < 4; i++) {
		dir.push_back(i); 
		dfs(cnt + 1); 
		dir.pop_back(); 
	}
	return; 
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL), cout.tie(NULL); 
	cin >> n >> m; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];  
			tmp[i][j] = a[i][j]; 
			if (a[i][j] != 0 && a[i][j] != 6)
				v.push_back({ i, j }); 
			if (a[i][j] == 1) {
				Camera[i][j][1] = true; 
			}
			else if (a[i][j] == 2) {
				Camera[i][j][1] = true; 
				Camera[i][j][3] = true; 
			}
			else if (a[i][j] == 3) {
				Camera[i][j][0] = true; 
				Camera[i][j][1] = true; 
			}
			else if (a[i][j] == 4) {
				Camera[i][j][0] = true; 
				Camera[i][j][1] = true; 
				Camera[i][j][3] = true; 
			}
			else if (a[i][j] == 5) {
				for (int r = 0; r < 4; r++) {
					Camera[i][j][r] = true; 
				}
			}
		}
	}
	dfs(0); 
	return 0; 
}