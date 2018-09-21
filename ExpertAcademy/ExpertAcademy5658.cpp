#include<iostream>
#include<algorithm>
#include<math.h>
#include<set>
#include<string>
#include<queue>

#define all(x) x.begin(),x.end()
#define N 29

using namespace std;

int t, n, k; char a[N];  vector<int> v; set<string> Word;
bool cmp(int a, int b) {
	return a > b; 
}
void rotate() { 
	char tmp[N];
	for (int i = 0; i < n - 1; i++)
		tmp[i + 1] = a[i];
	tmp[0] = a[n - 1];
	for (int i = 0; i < n; i++)
		a[i] = tmp[i];
	return;
}

void Save() {
	int period = n / 4; 
	string tmp; 
	for (int i = 0; i < n; i++) {
		tmp.push_back(a[i]);
		if (i%period == (period-1)) {
			Word.insert(tmp); 
			tmp.clear();
		}
	}
	return;
}

int Word_to_int(string s) {
	int num = 0; 
	for (int i = 0; i < s.length(); i++) {
		if ('A' <= s[s.length() - 1 - i] && s[s.length() - 1 - i] <= 'F')
			num += pow(16, i)*(int)(s[s.length()-1 -i]-'A'+10); 
		else 
			num += pow(16, i)*(s[s.length()-1-i] - '0'); 
	}
	return num; 
}

void Decimal_to_Hex() {
	set<string>::iterator iter; 
	for (iter = Word.begin(); iter != Word.end(); iter++) {
		string r = *iter; 
		v.push_back(Word_to_int(r));
	}
	return; 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> k;

		for (int i = 0; i < n; i++)
			cin >> a[i];

		for (int i = 0; i < n-1; i++) {
			Save();
			rotate();
		}
		Decimal_to_Hex(); 
		sort(all(v), cmp); 
		for (int i = 0; i < v.size(); i++) {
			if (i == k-1) {
				cout << '#' << tc << ' '<< v[i] << '\n'; 
				break; 
			}
		}
		v.clear(); Word.clear(); 
	}
	return 0;
}