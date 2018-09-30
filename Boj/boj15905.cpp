#include<iostream>
#include<vector>
#include<algorithm>

#define all(x) x.begin(),x.end()
#define N 66
using namespace std;

typedef pair<int, int> pii;
vector<pii> v; int n;

bool cmp(pii x, pii y) {
	if (x.first == y.first)
		return x.second < y.second;
	return x.first > y.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}
	sort(all(v), cmp);  n = 0;
	for (int i = 5; i < v.size(); i++) {
		if (v[4].first == v[i].first)
			n++;
		else
			break;
	}
	cout << n;

	return 0;
}