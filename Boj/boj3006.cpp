#include<iostream>
#include<algorithm>

#define N 100001

using namespace std; 

typedef long long ll; 
typedef pair<int, int> pii; 

int seg[N * 2], n, m; pii a[N]; 

int Sum(int i) {
	ll ans = 0; 
	while (i > 0) {
		ans += seg[i]; 
		i -= (i&-i); 
	}
	return ans;
}

void update(int i, int diff) {
	while (i <= n) {
		seg[i] += diff; 
		i += (i&-i); 
	}
	return; 
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL), cout.tie(NULL); 
	cin >> n; 
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first; 
		a[i].second = i; 
		update(i, 1); 
	}
	sort(a + 1, a + 1 + n); 
	int lft = 1; int rgt = n; 
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) { // odd
			cout << Sum(a[lft].second) - 1 << '\n'; 
			update(a[lft].second, -1); 
			lft++; 
		}
		else {  // even
			cout << Sum(n) - Sum(a[rgt].second - 1) - 1 << '\n'; 
			update(a[rgt].second - 1); 
			rgt--; 
		}
	}
	return 0; 
}