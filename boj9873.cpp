// DeepSleep
#include<iostream>
#include<algorithm>
#include<queue>

#define N 1001

using namespace std;

int n, m; vector<int> v; int a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n); int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int r = j + 1; r < n; r++) {
				int m = (a[j] - a[i]);
				if (m <= a[r] - a[j] && a[r] - a[j] <= 2 * m) 	ans++;
			}
		}
	}
	cout << ans;
	return 0;
}