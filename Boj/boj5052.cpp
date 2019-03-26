//2019y 03m 27d
//Minerba
#include<iostream>
#include<string>
#define ALPHA 26
#define MAX_N 100001
using namespace std; 

int TC, N, idx; 

struct node {
	int pt[ALPHA]; 
	bool finished; 
	void init() {
		finished = false; 
		for (register int i = 0; i < ALPHA; ++i)
			pt[i] = 0; 
	}
}nodes[MAX_N];

node* newNode() {
	nodes[idx].init(); 
	return &nodes[idx++]; 
}

struct Trie {
	node* root = newNode(); 

	bool insert(string inp) {
		node* tmp = root; int lng = inp.length(); 
		for (int i = 0; i < lng; i++) {
			if (!tmp->pt[inp[i] - '0']) {
				node* node = newNode();
				tmp->pt[inp[i] - '0'] = idx - 1;
			}
			else if (nodes[tmp->pt[inp[i]-'0']].finished) { 
				return false; 
			}
			tmp = &nodes[tmp->pt[inp[i]-'0']];
		}
		if (tmp->finished) return false; 
		for (int i = 0; i < 10; i++) {
			if (tmp->pt[i])
				return false; 
		}
		tmp->finished = true; 
		return true; 
	}
};

int main() {
	cin >> TC;  string inp; 
	while (TC--) {
		cin >> N; idx = 0; 
		bool res = true; 
		Trie tri; 
		while (N--) {
			cin >> inp; 
			if (!tri.insert(inp)) {
				res = false; 
			}
		}
		if (res) cout << "YES\n"; 
		else cout << "NO\n"; 
	}
	return 0; 
}