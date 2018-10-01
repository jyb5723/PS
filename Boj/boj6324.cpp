#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string inp;  int t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> inp;
		string protocol; string Host; string Port; string Path;
		int lng = inp.length();

		int pt = 0;
		while (inp[pt] != ':') {
			protocol.push_back(inp[pt]);
			pt++;
		}
		pt += 3;
		while (pt < lng && inp[pt] != ':' && inp[pt] != '/') {  // Host
			Host.push_back(inp[pt]);
			pt++;
		}
		if (pt < lng && inp[pt] == ':') { // port
			pt++;
			while (pt < lng && inp[pt] != '/') {
				Port.push_back(inp[pt]);
				pt++;
			}
		}


		if (pt < lng) { // path
			pt++;
			while (pt < lng) {
				Path.push_back(inp[pt]);
				pt++;
			}

		}
		cout << "URL #" << tc << '\n';
		cout << "Protocol = " << protocol << '\n';
		if (Host.size() != 0)
			cout << "Host     = " << Host << '\n';
		else if (!Host.size())
			cout << "Host     = <default>\n";
		if (Port.size() != 0)
			cout << "Port     = " << Port << '\n';
		else if (!Port.size())
			cout << "Port     = <default>\n";
		if (Path.size() != 0)
			cout << "Path     = " << Path << '\n';
		else if (!Path.size())
			cout << "Path     = <default>\n";
		cout << '\n';
	}
	return 0;
}