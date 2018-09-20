//2018 Y 09 M 19 D
//Minerba

#include<iostream>
#include<algorithm>
#include<vector>

#define N 1000001

using namespace std; 

int n, a[N]; 
int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL), cout.tie(NULL); 
	cin >> n; 
	for (int i = 0; i < n; i++)
		cin >> a[i]; 
	vector<int> v; 
	v.push_back(-1); 
	int ans = 0; 
	for (int i = 0; i < n; i++) {
		if (a[i] > v.back()) {
			v.push_back(a[i]); 
			ans++; 
		}
		else {
			auto j = lower_bound(v.begin(), v.end(), a[i]); 
			*j = a[i]; 
		}
	}
	cout << ans << '\n'; 
	return 0; 
}