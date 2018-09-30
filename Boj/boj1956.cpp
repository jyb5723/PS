#include<iostream>
#include<algorithm>
#define V 401
#define INT 1000000000
using namespace std;

int v, e, dist[401][401];

int main() {
	cin >> v >> e;

	for (int i = 0; i < v; i++)
		for (int j = 0; j < v; j++)
			dist[i][j] = INT;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a - 1][b - 1] = min(dist[a - 1][b - 1], c);
	}

	for (int k = 0; k < v; k++) {
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int ans = INT;
	for (int i = 0; i < v; i++)
		ans = min(ans, dist[i][i]);

	if (ans == INT) {
		cout << -1;
		return 0;
	}
	cout << ans;
	return 0;
}