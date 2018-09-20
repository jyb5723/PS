//DeepSleep
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>

#define N 1001
#define all(x) x.begin(),x.end()
#define dbg cout << "debugged\n";
#define sz(x) x.size() 
#define INT_ 0x7fffffff

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef double db;
typedef long double ld;

struct r
{
	string a, b, c;
}d;

int n; string s; vector<string> v;  map<vector<string>, int> mp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n; int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> s;
			v.push_back(s);
		}
		sort(v.begin(), v.end());
		mp[v]++;
		ans = max(mp[v], ans);
		v.clear();
	}
	cout << ans;
	return 0;
}