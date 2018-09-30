#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<map>

using namespace std;

int n, m;

map<string, set<string>> mp;  map<string, string> mp1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string Group, member; int Group_num; set<string> Group_;
		cin >> Group >> Group_num;
		for (int j = 0; j < Group_num; j++) {
			cin >> member;
			Group_.insert(member);
			mp1.insert({ member,Group });
		}
		mp.insert({ Group, Group_ });
	}
	while (m--) {
		string Girl;  int query_;
		cin >> Girl >> query_;
		if (query_) { // member 
			cout << mp1[Girl] << '\n';
		}
		else {  // group
			set<string>::iterator it;

			for (it = mp[Girl].begin(); it != mp[Girl].end(); it++) {
				cout << *it << '\n';
			}
		}
	}
	return 0;
}