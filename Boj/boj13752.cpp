#include<iostream>
#define N 101
using namespace std;
int a[N];
int main() {
	int n; 	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a[i]; j++)
			cout << "=";
		cout << '\n';
	}

	return 0;
}