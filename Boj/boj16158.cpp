// 2018 Y 09 M 19 D
// Minerba
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cmath>

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef unsigned long long llu;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
const ll MOD = 1e9 + 7;

struct node {
	int ch, p, val;
};
vector<node> v;

int gcd(int a, int b) {
	if (b == 0) return a;
	if (a > b) return gcd(b, a % b);
	return gcd(a, b % a);
}

int main() {
	int n, x, k, t;
	scanf("%d %d %d", &n, &x, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		v.push_back({ x * t, 100, 1 });
		v.push_back({ (200 - x) * t, 100, -1 });
	}

	sort(all(v), [](node v1, node v2) {
		if (v1.ch * v2.p == v2.ch * v1.p) return v1.val > v2.val;
		return v1.ch * v2.p < v2.ch * v1.p;
	});

	int cnt = 0;
	for (int i = 0; i < sz(v); i++) {
		cnt += v[i].val;
		if (cnt >= k) {
			t = gcd(v[i].ch, v[i].p);

			v[i].ch /= t;
			v[i].p /= t;
			if (v[i].p == 1) printf("%d", v[i].ch);
			else printf("%d/%d", v[i].ch, v[i].p);

			return 0;
		}
	}
	printf("-1");
}