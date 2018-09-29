#include<iostream>
#include<string.h>
#define N 100001
using namespace std;
int Fen[N * 2], a[N], t, n, m;
void update(int i, int diff) {
	while (i <= N * 2) {
		Fen[i] += diff;
		i += (i&(~i + 1));
	}
	return;
}
int Sum(int i) {
	int ans = 0;
	while (i > 0) {
		ans += Fen[i];
		i -= (i&(~i + 1));
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> t;
	while (t--) {
		memset(Fen, 0, sizeof(Fen));
		memset(a, 0, sizeof(a));
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			a[i] = i + m;  // m�� �ǲ����� �ø��� ���� 
			update(i + m, 1);  // m+1 ~ m+n (update to 1)
		}
		for (int i = 0; i < m; ++i) {
			int inp;  cin >> inp;
			cout << Sum(a[inp] - 1) << ' ';
			update(a[inp], -1);
			a[inp] = m - i;  // m-i ��° ��°� �׸�ŭ ����Ⱑ ���������� ��Ÿ��
			update(a[inp], 1);
		}
	}
	return 0;
}