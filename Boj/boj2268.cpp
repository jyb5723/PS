
#include<iostream>

#define N_ 1000001
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
#define lng(x) x.length()

using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int, int> pll;

int t, n, m; ll seg[N_ * 4];
void update(int pos, int val, int node, int x, int y) {
	if (pos < x || pos > y) return;
	if (x == y) {
		seg[node] = val;
		return;
	}
	int mid = (x + y) >> 1;
	update(pos, val, node << 1, x, mid);
	update(pos, val, (node << 1) + 1, mid + 1, y);
	seg[node] = seg[node << 1] + seg[(node << 1) + 1];
	return;
}

ll query(int lo, int hi, int node, int x, int y) {
	if (y < lo || x > hi)
		return 0;
	if (lo <= x && y <= hi)
		return seg[node];
	int mid = (x + y) >> 1;
	ll l = query(lo, hi, node << 1, x, mid);
	ll r = query(lo, hi, (node << 1) + 1, mid + 1, y);
	return l + r;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	ll a, b, c;
	while (m--) {
		cin >> a >> b >> c;
		if (!a) {
			int q = (b > c) ? b : c;
			int r = (b > c) ? c : b;
			cout << query(r, q, 1, 1, n) << '\n';
		}
		else
			update(b, c, 1, 1, n);
	}
	return 0;
}