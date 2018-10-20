#include<iostream>
#define N 101
using namespace std;

int chrows[8][4][4] = {
	{},
	{
		{ 0 },
		{ 0,0,0,0 }
	},
	{
		{ 0,0 },
	},
	{
		{ 0,0,1 },
		{ 0,-1 },
	},
	{
		{ 0,-1,-1 } ,
		{ 0,1 },
	},
	{
		{ 0,0,0 },{ 0,1 },{ 0,-1,0 },{ 0,-1 }
	},
	{
		{ 0,0,0 },{ 0,0 },{ 0,1,1 },{ 0,-2 }
	},
	{
		{ 0,0,0 },{ 0,2 },{ 0,0,-1 },{ 0,0 }
	}
};
int clen[8] = { 0,2,1,2,2,4,4,4 };   
int len[8][4] = { { 0 },{ 1,4 },{ 2 },{ 3,2 },{ 3,2 },{ 3,2,3,2 },{ 3,2,3,2 },{ 3,2,3,2 } }; 
int a[N];
int main() {
	int c, b;
	cin >> c >> b;
	for (int i = 0; i < c; i++)
		cin >> a[i];
	int ans = 0;
	for (int i = 0; i < c; i++) {   
		for (int r = 0; r < clen[b]; r++) {  
			if (i + len[b][r] > c) continue;  

			int h[4];
			h[0] = a[i];
			for (int j = 1; j < len[b][r]; j++) 
				h[j] = h[0] + chrows[b][r][j];

			bool can = true;
			for (int j = 1; j < len[b][r]; j++) {
				if (h[j] != a[i + j]) {
					can = false;
					break;
				}
			}
			ans += can;
		}
	}
	cout << ans;
	return 0;
}