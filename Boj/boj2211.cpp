#include<iostream>
#include<queue>
#include<vector>

#define N 1001     
#define INT 0x7fffffff
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int, int> pll;

int par[N], n, m, dst[N]; vector<pll> v[N];
priority_queue<pll> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a,c });
	}
	for (int i = 0; i <= 1000; i++)
		dst[i] = INT;

	dst[1] = 0;  
	pq.push({ 0, 1 });   
	par[1] = 1;

	while (!pq.empty()) {
		int Cur = pq.top().second;
		int dis = -pq.top().first;
		pq.pop();

		if (dst[Cur] < dis) continue;

		for (int i = 0; i < v[Cur].size(); ++i) {
			int nxt = v[Cur][i].first;
			int n_dis = dis + v[Cur][i].second;

			if (dst[nxt] > n_dis) {
				dst[nxt] = n_dis;
				par[nxt] = Cur;
				pq.push({ -n_dis, nxt });
			}
		}
	}
	cout << n - 1 << '\n';   
	for (int i = 2; i <= n; i++)  
		cout << par[i] << ' ' << i << '\n';
	return 0;
}