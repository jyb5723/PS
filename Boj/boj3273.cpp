#include<iostream>
#include<algorithm>
#define N 100001
using namespace std;

int n, ar[N], x;

int B_Search(int x) {
	int lft = 0, rgt = n - 1;
	while (lft <= rgt) {
		int mid = (lft + rgt) >> 1;
		if (ar[mid] == x)
			return mid;
		else if (ar[mid] > x)
			rgt = mid - 1;
		else if (ar[mid] < x)
			lft = mid + 1;
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> ar[i];
	cin >> x;
	sort(ar, ar + n); int ans = 0;

	for (int i = 0; i < n; i++) {
		int s = B_Search(x - ar[i]);
		if (ar[i] * 2 == x) continue;
		if (s == -1) continue;
		ans++;
	}
	cout << ans / 2;
	return 0;
}