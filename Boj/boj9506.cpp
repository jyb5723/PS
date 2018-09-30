#include<iostream>
#include<vector>
#define N (int)1e5
using namespace std;

int n;  bool tr[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	tr[1] = true;
	for (int i = 2; i*i <= N; i++) {
		tr[i] = true;
		for (int j = i + i; j <= N; j += i) {
			tr[j] = true;
		}
	}
	int ans;
	while (cin >> n) {
		if (n == -1) return 0;
		vector<int> v; ans = 0;
		for (int i = 1; i < n; i++) {
			if (!(n%i)) {
				ans += i; v.push_back(i);
			}
		}
		if (ans == n) {
			cout << n << " = " << v[0] << ' ';
			for (int i = 1; i < v.size(); i++) {
				cout << '+' << ' ' << v[i] << ' ';
			}
			cout << '\n';
		}
		else
			cout << n << " is NOT perfect.\n";
	}

	return 0;
}