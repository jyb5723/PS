#include<iostream>
#include<vector>
#include<algorithm>
#define N 12
#define MAX_ 1000000000
#define MIN_ -1000000000

using namespace std;

int n, a[N], oper[4]; vector<int> v; int cnt1;
int Min = MAX_; int Max = MIN_;
int chk[N][4];

int calc() {
	int Sum = a[0]; int pt = 1, pt1 = 0;
	while (pt < n) {
		if (v[pt1] == 0) {
			Sum += a[pt++];
			pt1++;
		}
		else if (v[pt1] == 1) {
			Sum -= a[pt++];
			pt1++;
		}
		else if (v[pt1] == 2) {
			Sum *= a[pt++];
			pt1++;
		}
		else if (v[pt1] == 3) {
			Sum /= a[pt++];
			pt1++;
		}
	}
	return Sum;
}

void dfs(int cnt) {
	if (cnt == n - 1) {
		int s = calc();
		Min = min(Min, s);
		Max = max(s, Max);
		cnt1++;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (oper[i]) {
			oper[i]--; v.push_back(i);
			dfs(cnt + 1);
			oper[i]++; v.pop_back();
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}
	dfs(0);
	cout << Max << '\n' << Min << '\n';
	return 0;
}