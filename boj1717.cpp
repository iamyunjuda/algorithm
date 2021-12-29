#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MAX = 1000000 + 1;

int n, m;
int parent[MAX] = {-1,};
int level[MAX];
int find(int a) {
	if (a == parent[a]) return a;
	return parent[a] = find(parent[a]);


}

void Union(int a, int b) {
	a = find(parent[a]);
	b = find(parent[b]);
	if (a != b) {
		if (level[a] < level[b]) {
			parent[a] = b;
			level[a] += level[b];
		}
		else {
			parent[b] = a;
			level[b] += level[a];
		}

	
	}

}

int main(void)

{
	ios_base::sync_with_stdio(0);
	cin.tie(0); //cin 실행속도 향상
	cin >> n>> m;
	for (int i = 1; i < MAX; i++) {
		parent[i] = i;
		level[i] = 0;
	}
	for (int i = 0; i < m; i++) {
		int check, a, b;
		cin >> check >> a >> b;
		if (check == 0) {
			Union(a, b);
		}
		else {
			int t1 = find(a);
			int t2 = find(b);
			if (t1 == t2) cout << "YES\n";
			else cout << "NO\n";
		}
	}



}
