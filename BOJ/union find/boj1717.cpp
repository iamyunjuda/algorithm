// 유니온 파인드 -> find + union(merge)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;

int parent[1000001];
int Find(int x) {
	if (x == parent[x]) {
		return x;

	}
	else {
		int y = Find(parent[x]);
		parent[x] = y;
		return y;

	}

}
void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	parent[y] = x;


}



int main() {

	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		parent[i] = i;

	}
	int op, a, b;
	while (m--) {
		cin >> op >> a >> b;
		if (op == 0) {
			Union(a, b);
		}
		else {
		
			int a_parent = Find(a);
			int b_parent = Find(b);
			if (a_parent == b_parent) {
				cout << "YES\n";

			}
			else {
				cout << "NO\n";
			}
		}

	}
	return 0;
}
