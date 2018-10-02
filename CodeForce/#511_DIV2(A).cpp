#include<iostream>
using namespace std; 

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL), cout.tie(NULL); 
	int t, n, k; cin >> t; 
	k = t % 3; 
	if (!k || k == 1) {
		cout << "1 " << "1 " << t - 2 << '\n'; 
	}
	else if (k == 2) {
		cout << "1 " << "2 " << t - 3 << '\n'; 
	}

	return 0; 
}