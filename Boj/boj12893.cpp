#include<iostream>
#include<queue>
using namespace std;

int n, m, u, v;

int main() {
	cin >> n >> m;
	vector<vector<int>> s(n + 1);
	while (m--) {
		cin >> u >> v;
		s[u].push_back(v);
		s[v].push_back(u);
	}
	vector<int> r(n + 1, 0);
	bool chk = true;
	for (int i = 1; i <= n; i++) {
		if (!chk) break; 
		if (r[i]) continue;

		queue<int> q; q.push(i);
		r[i] = 1;
		while (!q.empty()) {
			if (!chk) break; 
			int cur = q.front();
			q.pop();
			for (int i = s[cur].size() - 1; i >= 0; i--) {
				if (r[s[cur][i]]) {
					if (r[s[cur][i]] == r[cur]) {
						chk = false;
						break;
					}
				}
				else {
					r[s[cur][i]] = -r[cur]; 
					q.push(s[cur][i]);
				}
			}
		}
	}
	cout << chk << '\n'; 
	return 0;
}