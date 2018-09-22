#include <iostream>
#include <algorithm>
using namespace std;

int r, c; char a[21][21]; int dp[21][21];

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> a[i][j];
	dp[0][0] = 1;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			for (int k = 1; i + k < r; k++)
				for (int l = 1; j + l < c; l++)
					if (a[i][j] != a[i + k][j + l])
						dp[i + k][j + l] += dp[i][j];
	cout << dp[r - 1][c - 1];
}