#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>

#define N 11
#define INT 0x7fff0000

using namespace std;

int t, n, score[N]; char a[N][N]; int lng[N];
string samsung; int ans, alpha[26]; int Word[26];

bool chk() {
	for (int i = 0; i < 26; i++) {
		if (alpha[i] < Word[i])
			return false;
	}
	return true;
}

void dfs(int idx, int Sum) {
	if (idx == n - 1) {
		if (chk())
			ans = min(ans, Sum);
		return;
	}
	if (idx + 1 < n) {
		for (int i = 0; i < lng[idx + 1]; i++)
			alpha[a[idx + 1][i] - 'A']++;
		dfs(idx + 1, Sum + score[idx + 1]);
		for (int i = 0; i < lng[idx + 1]; i++)
			alpha[a[idx + 1][i] - 'A']--;
		dfs(idx + 1, Sum);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> t; string s = "SAMSUNG";

	for (int tc = 1; tc <= t; tc++) {
		cin >> n;    ans = INT;
		for (int i = 0; i < n; i++) {
			int l;	cin >> lng[i];
			for (int j = 0; j < lng[i]; j++)
				cin >> a[i][j];
			cin >> score[i];
		}
		for (int i = 0; i < s.length(); i++)
			Word[s[i] - 'A']++;
		dfs(-1, 0);
		if (ans != INT)
			cout << '#' << tc << ' ' << ans << '\n';
		else
			cout << '#' << tc << ' ' << -1 << '\n';
		memset(a, NULL, sizeof(a));
		memset(score, 0, sizeof(score));
		memset(Word, 0, sizeof(Word));
		memset(alpha, 0, sizeof(alpha));
	}
	return 0;
}