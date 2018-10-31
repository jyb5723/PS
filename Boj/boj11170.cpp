#pragma once
#ifndef mod (int)(1e9+7)
#include<iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int lo, hi;
		cin >> lo >> hi;
		int Zero_Count = 0;
		for (int i = lo; i <= hi; i++) {
			int number = i;
			if (!number) {
				Zero_Count++;
				continue;
			}
			while (number) {
				if (!(number % 10)) Zero_Count++;
				number /= 10;
			}
		}
		cout << Zero_Count << '\n';
	}
	return 0;
}
#endif 