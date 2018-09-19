#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>

#define N 1001

using namespace std;

int n, m;
int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };  
int Cur_d, x, y;    int Up, Down, Left, Right;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	while (n--) {
		string s;
		cin >> s; Cur_d = 0;
		x = 500, y = 500;
		Up = 500, Down = 500, Left = 500, Right = 500;
		int lng = s.length();
		for (int i = 0; i < lng; i++) {
			if (s[i] == 'R') { Cur_d = (Cur_d + 1) % 4; continue; }
			if (s[i] == 'L') {
				Cur_d -= 1;
				if (Cur_d < 0)	Cur_d = 3;
				continue;
			}
			if (s[i] == 'B')
				x += dx[(Cur_d + 2) % 4], y += dy[(Cur_d + 2) % 4];
			if (s[i] == 'F')
				x += dx[Cur_d], y += dy[Cur_d];
			Up = min(Up, x);
			Down = max(Down, x);
			Left = min(Left, y);
			Right = max(Right, y);
		}
		cout << (Down - Up)*(Right - Left) << '\n';
	}
	return 0;
}