#include<iostream>
#define N (int)(1e6+1)
using namespace std;

bool JYB(string pattern, string parent) {
	string temp;
	for (int i = 0; i < parent.size(); i++) {
		if (parent[i] - '0' <= 9 && parent[i] - '0' >= 0) continue;
		else temp.push_back(parent[i]);
	}
	for (int i = 0; i < temp.size(); i++)
		parent[i] = temp[i];
	int patternSize = pattern.size();
	int parentSize = parent.size();

	int parentHash = 0, patternHash = 0, power = 1;
	for (int i = 0; i <= parentSize - patternSize; i++) {
		if (!i) {
			for (int j = 0; j < patternSize; j++) {
				parentHash += (parent[patternSize - 1 - j] * power);
				patternHash += (pattern[patternSize - 1 - j] * power);
				if (j < patternSize - 1) power *= 2;
			}
		}
		else {
			parentHash = 2 * (parentHash - parent[i - 1] * power) + (parent[patternSize - 1 + i]);
		}
		if (parentHash == patternHash) {
			bool finded = true;
			for (int j = 0; j < patternSize; j++) {
				if (parent[i + j] != pattern[j]) {
					finded = false;
					break;
				}
			}
			if (finded) {
				return true;
			}
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	char parent[N], pattern[N];
	cin >> parent; cin >> pattern;

	if (JYB(pattern, parent))
		cout << 1 << '\n';
	else
		cout << 0 << '\n';

	return 0;
}