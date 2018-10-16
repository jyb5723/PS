#include<iostream>
#define N 21
#define INT 2000000
using namespace std;

int ar[N], n; bool chk[INT];

void dfs(int idx, int Sum) {
	chk[Sum] = true;
	for (int i = idx + 1; i < n; i++) {
		dfs(i, Sum + ar[i]);
	}
	return;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> ar[i];
	dfs(-1, 0);
	for (int i = 1; i <= INT; i++) {
		if (!chk[i]) {
			cout << i << '\n';
			return 0;
		}
	}
	return 0;
}