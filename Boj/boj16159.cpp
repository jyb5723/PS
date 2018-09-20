// 2018 Y 09 M 19 D
// Minerba
#include<iostream>
#include<queue>
#include<algorithm>
#include<stdio.h>
#include<string>

#define N 101
using namespace std;

#pragma warning(disable:4996)

char q; vector<char> v; char a[101][101];
int Num[10] = { 10, 6, 14,9,11,13, 12, 8, 16, 15 }, col;
vector<int> permut; vector<char> r[10];

int Num_chk(int x, int y) {
	int cnt_ = 0; vector<char> e;
	for (int i = x; i < x + 7; i++) {
		for (int j = y; j < y + 6; j++) {
			if (a[i][j] == '1')
				cnt_++;
			e.push_back(a[i][j]);
		}
	}
	for (int i = 0; i < 10; i++)
		if (cnt_ == Num[i]) {
			if (!r[i].size()) {
				for (int j = 0; j < e.size(); j++) {
					r[i].push_back(e[j]);
				}
			}
			return i;
		}
}

void Print() {
	for (int i = 0; i < 7; i++) {
		for (int s = 0; s < permut.size(); s++) {
			for (int j = i * 6; j < i * 6 + 6; j++) {
				cout << r[permut[s]][j];
			}
		}
		cout << '\n';
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

	for (int i = 0; i < 7; i++) {
		string s;  cin >> s;
		for (int j = 0; j < s.length(); j++)
			v.push_back(s[j]);
	}

	int sz = v.size();   col = sz / 7;   int pt = 0;
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < col; j++)
			a[i][j] = v[pt++];

	for (int j = 0; j < col; j += 6)
		permut.push_back(Num_chk(0, j));

	if (!next_permutation(permut.begin(), permut.end()))   // 다음 순열 저장
		cout << "The End\n";
	else
		Print();
	return 0;
}