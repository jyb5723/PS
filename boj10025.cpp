#include<iostream>
#include<algorithm>
#include<queue>

#define N 11

using namespace std;

int t, A, m;   int map[N][N];
int dx[] = { 0,-1,0,1,0 }, dy[] = { 0,0,1,0,-1 };  // 0 ,상, 우, 하 , 좌
int loc_ax, loc_ay, loc_bx, loc_by;    vector<int> a, b; 
int bc[9];    int charge_map[N][N][9];   // 충전 영역 표시 

void Charge(int x, int y, int num, int c) {  // 몇번 배터리의 충전인지  
	queue<pair<int, int>> q; 
	for (int i = 0; i < c; i++) {
		int sz = q.size(); 
		for (int j = 0; j < sz; j++) {
			for (int r = 1; r < 5; r++) {
				int nx = q.front().first; int ny = q.front().second; 
				q.pop(); 
				charge_map[nx][ny][num] = true; 
				if (nx < 1 || nx > 10 || ny < 1 || ny > 10) continue; 
				if (!charge_map[nx][ny][num]) {
					charge_map[nx][ny][num] = true; 
					q.push({ nx, ny }); 
				}
			}
		}
	}
	return; 
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> m >> A;
	/*for (int i = 0; i < m; i++) {
		int x;  cin >> x; 
		a.push_back(x); 
	}

	for (int i = 0; i < m; i++) {
		int x;  cin >> x;
		b.push_back(x);
	}*/

	/*int x, y, c, power; 
	for (int i = 1; i <= A; i++){
		cin >> x >> y >> c >> power; 
		Charge(x, y, i, power); 
	}*/

	//cout << '\n'; 
	//for (int i = 0; i < 10; i++) {
	//	for (int j = 0; j < 10; j++) {
	//		cout << charge_map[i][j][1] << '\n'; 
	//	}
	//	cout << '\n'; 
	//}

	return 0;
}