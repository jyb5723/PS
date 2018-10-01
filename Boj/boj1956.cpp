#include<iostream>
#include<string>
#include<vector>
using namespace std; 

string inp; vector<char> v; 

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL), cout.tie(NULL); 
	cin >> inp; 
	for (int i = 0; i < inp.length(); i++) {
		cout << 1; 
		if (inp[i] == ')') {
			while (v.back() != '(') {
				cout << v.back(); 
				v.pop_back(); 
			}
			v.pop_back(); 
		}
		else if (inp[i] == '*' || inp[i] == '/' || inp[i] == '+' || inp[i] == '-' || inp[i] == '(') {  // ¿¬»êÀÚ
			v.push_back(inp[i]); 
		}
		else {
			cout << inp[i]; 
		}
	}


	return 0; 
}