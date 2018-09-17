#include<iostream>
using namespace std; 

int n, a, d, l; 
int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL), cout.tie(NULL); 
	cin >> n >> a >> d; 
	int Cnt = 0; 
	for (int i = 0; i < n; i++) {
		cin >> l; 
		if (a == l) Cnt++, a+=d;
	}
	cout << Cnt << '\n'; 
	return 0; 
}