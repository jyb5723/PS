//2019Ҵ 04�� 08�� [boj 17136]
//Minerba
#include<iostream>
#include<algorithm>
#include<vector>

#define N 11

using namespace std;

typedef pair<int, int> pii;

int map[N][N], ans = 0x7fffffff; vector<pii> v;
int pap[] = { 5, 5, 5, 5, 5, 5 };
bool chk[N][N]; vector<pair<int, pii>> s; 

int Square(int x, int y) { // �ִ� �簢�� ũ�� ���� 
	int lng = 1;
	bool res = true;
	while (res && lng <= 5 && x + lng <= 10 && y + lng <= 10) {
		for (int i = x; i < x + lng; i++) {
			for (int j = y; j < y + lng; j++) {
				if (!map[i][j]) {
					res = false;
					break;
				}
			}
			if (!res) break;
		}
		if (res) lng++;
	}
	return lng - 1;
}

bool vist(int x, int y, int lng) {
	for (int i = x; i < x + lng; i++){
		for (int j = y; j < y + lng; j++) {
			if (chk[i][j]) return false; 
		}
	}
	return true;
}

void complete(int x, int y, int lng) {
	for (int i = x; i < x + lng; i++) 
		for (int j = y; j < y + lng; j++) 
			chk[i][j] = true; 
	return; 
}


void clear(int x, int y, int lng) {
	for (int i = x; i < x + lng; i++)
		for (int j = y; j < y + lng; j++)
			chk[i][j] = false;
	return;
}

void dfs(int idx, int cnt) {
	if (idx == v.size()) {   // ���� ������ ���
		ans = min(ans, cnt);
		return;
	}
	if (cnt > ans) return;

	register int xx = v[idx].first; register int yy = v[idx].second;
	// 1�� ���� ��ǥ�� 
	if (chk[xx][yy]) {  // �̹� ������ �簢���� ���
		dfs(idx + 1, cnt);
		return;
	}
	register int size_ = Square(xx, yy);

	for (int i = size_; i >=1; i--) {   // ������ i¥�� �����̰� ����������� 
		if (pap[i] && vist(xx, yy, i)) {
			pap[i]--;
			complete(xx, yy, i);
			dfs(idx + 1, cnt + 1);
			clear(xx, yy, i);
			pap[i]++;
		}
	}
	return;
}

int main() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> map[i][j];
			if (map[i][j])
				v.push_back({ i, j });
		}
	}

	dfs(0, 0);
	if (ans == 0x7fffffff)
		cout << -1 << '\n';
	else
		cout << ans << '\n';
	return 0;
}