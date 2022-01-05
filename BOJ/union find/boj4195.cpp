#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int T, F;
string friend1, friend2;
int parent[100005];
int level[100005];

int Find(int a) {
	if (parent[a] == a) return a;
	return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {

	a = Find(a);
	b = Find(b);
	if (a != b) {
		if (level[a] < level[b]) swap(a, b);
		parent[b] = a;
		level[a] += level[b];
		level[b] = 0;

	
	
	}

}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> F;

		map<string, int> m;
		int index = 0;
		for (int i = 0; i < F; i++) {
			cin >> friend1 >> friend2;
			if (m.find(friend1) == m.end()) m[friend1] = index++;
			if (m.find(friend2) == m.end()) m[friend2] = index++;

			int check1 = Find(m[friend1]);
			int check2 = Find(m[friend2]);

			if (check1 == check2)cout << max(level[check1], level[check2]) << "\n";
			else {
				Union(check1, check2);
				cout << max(level[check1], level[check2]) << "\n";
			
			}


		
		}
	

	
	}

	return 0;

}
