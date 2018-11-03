#include<iostream>
#include<queue>
#define N    32001
using namespace std; 

int n, m, ar[N];  vector<int> v[N]; priority_queue<int> pq; 

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL), cout.tie(NULL); 
	cin >> n >> m; 
	for (int i = 0; i < m; i++) {
		
		int x, y; 
		cin >> x >> y; 
		v[x].push_back(y); 
		ar[y]++; 
	}

	for (int i = 1; i <= n; i++) {
		if (!ar[i]) {
			pq.push(-i); 
		}
	}
	while (pq.size()) {
		int here = -pq.top();
		pq.pop(); 
		cout << here << ' ';
		for (int i = 0; i < v[here].size(); i++) {
			ar[v[here][i]]--; 
			if (!ar[v[here][i]]) {
				pq.push(-v[here][i]); 
			}
		}
	}
	return 0; 
}