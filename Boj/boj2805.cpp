#include<iostream>
#define N (int)(1e6+1)

using namespace std;

typedef long long ll; 

int n, m, a[N];  ll lft, rgt; 

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL), cout.tie(NULL); 
	cin >> n >> m; 
	for (int i = 0; i < n; i++)
		cin >> a[i]; 
	lft = 0; rgt = 2 * (1e9) + 1; 

	while (lft <= rgt) {
		ll mid = (lft + rgt) >> 1; 
		ll ans = 0; 
		for (int i = 0; i < n; i++) 
			if (a[i] > mid) ans += (a[i] - mid);
		if (ans >= m) lft = mid + 1; 
		else rgt = mid - 1; 
	}
	cout << rgt; 
	return 0;
}